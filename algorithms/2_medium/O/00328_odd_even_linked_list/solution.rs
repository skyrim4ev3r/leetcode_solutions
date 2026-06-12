impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut odd_dummy = ListNode::new(0);
        let mut even_dummy = ListNode::new(0);

        let mut odd_prev = &mut odd_dummy;
        let mut even_prev = &mut even_dummy;
        let mut is_odd = true;
        let mut curr_bx_opt = head;

        while let Some(mut curr_bx) = curr_bx_opt {
            let next = curr_bx.next.take();

            if is_odd {
                odd_prev.next = Some(curr_bx);
                odd_prev = odd_prev.next.as_mut().unwrap();
            } else {
                even_prev.next = Some(curr_bx);
                even_prev = even_prev.next.as_mut().unwrap();
            }

            curr_bx_opt = next;
            is_odd = !is_odd;
        }

        odd_prev.next = even_dummy.next;

        odd_dummy.next
    }
}
