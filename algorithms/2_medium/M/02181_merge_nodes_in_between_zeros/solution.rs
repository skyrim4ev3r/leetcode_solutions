// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut res_head: Option<Box<ListNode>> = None;
        let mut res_curr: Option<&mut Box<ListNode>> = None;

        let mut curr = head.unwrap().next;
        let mut sum = 0;

        while let Some(curr_unwrap) = curr {
            if curr_unwrap.val != 0 {
                sum += curr_unwrap.val;
            } else {
                let new_node = Some(Box::new(ListNode::new(sum)));
                sum = 0;

                if res_curr.is_none() {
                    res_head = new_node;
                    res_curr = res_head.as_mut();
                } else {
                    let res_curr_unwrap =  res_curr.unwrap();
                    res_curr_unwrap.next = new_node;
                    res_curr = res_curr_unwrap.next.as_mut();
                }
            }

            curr = curr_unwrap.next;
        }

        res_head
    }
}
