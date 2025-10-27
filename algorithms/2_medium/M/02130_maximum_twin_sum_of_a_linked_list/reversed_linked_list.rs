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
    pub fn pair_sum(mut head: Option<Box<ListNode>>) -> i32 {

        let mut count = 0_i32;
        let mut curr_opt = head.as_ref();

        while let Some(curr) = curr_opt {
            count += 1;
            curr_opt = curr.next.as_ref();
        }

        let mut head1_opt: Option<Box<ListNode>> = head;
        let mut head2_opt: Option<Box<ListNode>> = None;
        let half = count / 2;

        for i in 1..=half {
            let mut curr = head1_opt.unwrap();
            head1_opt = curr.next.take();
            curr.next = head2_opt;
            head2_opt = Some(curr);
        }

        let mut max = i32::MIN;

        while let (Some(head1), Some(head2)) = (head1_opt, head2_opt) {
            max = max.max(head1.val + head2.val);
            head1_opt = head1.next;
            head2_opt = head2.next;
        }

        max
    }
}
