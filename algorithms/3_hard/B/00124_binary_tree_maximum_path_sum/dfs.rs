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
    fn dfs_calculate_max_path_sum(curr_node_rc_opt: Option<Rc<RefCell<TreeNode>>>, max_path_sum: &mut i32) -> i32 {

        if let Some(curr_node_rc)  = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            let left_max_path_sum = 0_i32.max(Self::dfs_calculate_max_path_sum(curr_node.left.clone(), max_path_sum));
            let right_max_path_sum = 0_i32.max(Self::dfs_calculate_max_path_sum(curr_node.right.clone(), max_path_sum));

            let path_sum_from_curr = curr_node.val + left_max_path_sum + right_max_path_sum;

            *max_path_sum = (*max_path_sum).max(path_sum_from_curr);

            return curr_node.val + left_max_path_sum.max(right_max_path_sum);
        }

        0
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_path_sum = i32::MIN;

        Self::dfs_calculate_max_path_sum(root, &mut max_path_sum);

        max_path_sum
    }
}
