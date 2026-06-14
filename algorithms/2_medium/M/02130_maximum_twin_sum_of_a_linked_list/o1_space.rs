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
    fn calc_len(mut head: Option<&Box<ListNode>>) -> isize {
        let mut len = 0_isize;
        while let Some(node) = head {
            head = node.next.as_ref();
            len += 1;
        }
        len
    }

    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        debug_assert!(head.is_some());
        let len = Self::calc_len(head.as_ref());
        debug_assert!((len & 1) == 0);
        let half = len / 2;

        let mut h2_opt: Option<Box<ListNode>> = head;
        let mut h1_opt: Option<Box<ListNode>> = None;

        for _ in 0..half {
            let mut h2 = h2_opt.unwrap();
            let h2_next = h2.next.take();
            h2.next = h1_opt;
            h1_opt = Some(h2);
            h2_opt = h2_next; 
        }

        let mut max = i32::MIN;

        while let (Some(curr1), Some(curr2)) = (h1_opt, h2_opt) {
            let curr_sum = curr1.val + curr2.val;
            max = max.max(curr_sum);
            h1_opt = curr1.next;
            h2_opt = curr2.next;
        }

        max
    }
}
