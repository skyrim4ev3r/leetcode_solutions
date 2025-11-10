impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }

        let mut odd_head = Some(Box::new(ListNode::new(0)));
        let mut even_head = Some(Box::new(ListNode::new(0)));

        let mut odd_current = odd_head.as_mut();
        let mut even_current = even_head.as_mut();
        let mut is_odd = true;

        let mut curr = head;
        while let Some(mut node) = curr {
            curr = node.next.take();

            if is_odd {
                if let Some(odd) = odd_current {
                    odd.next = Some(node);
                    odd_current = odd.next.as_mut();
                }
            } else {
                if let Some(even) = even_current {
                    even.next = Some(node);
                    even_current = even.next.as_mut();
                }
            }
            is_odd = !is_odd;
        }

        if let Some(odd) = odd_current {
            odd.next = even_head.unwrap().next.take();
        }

        odd_head.unwrap().next
    }
}
