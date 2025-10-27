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
        let mut nums: Vec<i32> = Vec::new();

        while let Some(node) = head {
            nums.push(node.val);
            head = node.next;
        }

        let mut left = 0;
        let mut right = nums.len() - 1;
        let mut max = i32::MIN;

        while left < right {
            max = max.max(nums[left] + nums[right]);
            left += 1;
            right -= 1;
        }
        
        max
    }
}
