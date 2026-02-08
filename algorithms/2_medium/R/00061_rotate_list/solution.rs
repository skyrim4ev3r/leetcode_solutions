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

    #[inline(always)]
    fn calc_len_and_shift_count(mut curr_opt: Option<&Box<ListNode>>, k: i32) -> (i32, i32) {
        let mut len = 0_i32;

        while let Some(curr) = curr_opt {
            len += 1;
            curr_opt = curr.next.as_ref();
        }

        let shift_count = if len == 0 { 0 } else { (len - k % len) % len };

        (len, shift_count)
    }

    #[inline(always)]
    fn split_into_two_list(
        mut head_opt: Option<Box<ListNode>>, shift_count: i32
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        let mut dummy = Box::new(ListNode::new(0));
        dummy.next = head_opt;
        let mut prev = &mut dummy;

        for _ in 0..shift_count {
            prev = prev.next.as_mut().unwrap();
        }

        let h2 = prev.next.take();
        let h1 = dummy.next.take();

        (h1, h2)
    }

    pub fn rotate_right(mut head_opt: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let (len, shift_count) = Self::calc_len_and_shift_count(head_opt.as_ref(), k);

        if len <= 1 || shift_count == 0 {
            return head_opt;
        }

        let (h1, mut h2) = Self::split_into_two_list(head_opt, shift_count);

        let mut prev = h2.as_mut().unwrap();

        while prev.next.is_some() {
            prev = prev.next.as_mut().unwrap();
        }

        prev.next = h1;

        h2
    }
}
