impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        let mut dummy: Box<ListNode> = Box::new(ListNode::new(0));
        let mut prev = dummy.as_mut();
        let mut offset = 0_i32;

        while l1.is_some() || l2.is_some() {
            let mut num = 0_i32;

            if let Some(mut node) = l1 {
                num += node.val;
                l1 = node.next;
            }

            if let Some(mut node) = l2 {
                num += node.val;
                l2 = node.next;
            }

            num += offset;
            offset = 0;
            if num >= 10 {
                offset = 1;
                num -= 10;
            }

            let new_node: Option<Box<ListNode>> = Some(Box::new(ListNode::new(num)));
            prev.next = new_node;
            prev = prev.next.as_mut().unwrap();
        }

        if offset > 0 {
            let new_node: Option<Box<ListNode>> = Some(Box::new(ListNode::new(offset)));
            prev.next = new_node;
        }

        dummy.next
    }
}
