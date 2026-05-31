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
    fn has_path_sum_helper(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, prev_sum: i32, target_sum: i32) -> bool {
        match curr_node_rc_opt {
            None => {
                return false
            },
            Some(curr_node_rc) => {
                let curr_node = curr_node_rc.borrow();
                let is_leaf = (curr_node.left.is_none()) && (curr_node.right.is_none());
                let curr_sum = prev_sum + curr_node.val;

                return (is_leaf && curr_sum == target_sum) || 
                        Self::has_path_sum_helper(curr_node.left.as_ref(), curr_sum, target_sum) ||
                        Self::has_path_sum_helper(curr_node.right.as_ref(), curr_sum, target_sum)
            },
        };
    }

    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        let prev_sum = 0_i32;
        Self::has_path_sum_helper(root.as_ref(), prev_sum, target_sum)
    }
}
