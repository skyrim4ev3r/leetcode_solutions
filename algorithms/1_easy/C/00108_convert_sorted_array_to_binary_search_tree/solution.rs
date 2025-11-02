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
    fn recursive(nums: &Vec<i32>, l: usize, r: usize) -> Option<Rc<RefCell<TreeNode>>> {
        let mid = (l + r) / 2;       
        let mut new_node = Some(Rc::new(RefCell::new(TreeNode::new(nums[mid]))));
        if l < mid {
            new_node.as_mut().unwrap().borrow_mut().left = Self::recursive(nums, l, mid - 1);
        }
        if mid < r {
            new_node.as_mut().unwrap().borrow_mut().right = Self::recursive(nums, mid + 1, r);
        }

        new_node
    }
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::recursive(&nums, 0, nums.len() - 1)
    }
}
