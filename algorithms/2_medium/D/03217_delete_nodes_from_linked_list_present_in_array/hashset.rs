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
use std::collections::HashSet;

impl Solution {
    pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut hashset: HashSet<i32> = nums.into_iter().collect::<HashSet<_>>();

        let mut dummy = ListNode::new(0);

        let mut prev = &mut dummy;
        let mut curr_opt = head;

        while let Some(mut curr) = curr_opt {
            curr_opt = curr.next.take();

            if !hashset.contains(&curr.val) {
                prev.next = Some(curr);
                prev = prev.next.as_mut().unwrap().as_mut();
            }
        }

        dummy.next
    }
}
