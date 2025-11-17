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
    pub fn get_decimal_value(mut head_opt: Option<Box<ListNode>>) -> i32 {
        let mut res = 0_i32;

        while let Some(mut head) = head_opt {
            res = res << 1;
            res |= (head.val);
            head_opt = head.next.take();
        }

        res
    }
}
