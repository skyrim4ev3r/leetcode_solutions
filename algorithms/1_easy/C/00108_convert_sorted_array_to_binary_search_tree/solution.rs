// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn arr_to_bst_helper(nums: &Vec<i32>, left: isize, right: isize) -> Option<Rc<RefCell<TreeNode>>> {
        if left > right {
            return None;
        }

        let mid = left + (right - left) / 2;       
        let mut new_node = TreeNode::new(nums[mid as usize]);
        new_node.left = Self::arr_to_bst_helper(nums, left, mid - 1);
        new_node.right = Self::arr_to_bst_helper(nums, mid + 1, right);
        Some(Rc::new(RefCell::new(new_node)))
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::arr_to_bst_helper(&nums, 0, (nums.len() as isize) - 1)
    }
}
