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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, max_path_sum: &mut i32) -> i32 {
        if let Some(curr_node_rc)  = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            let left_sum = Self::dfs(curr_node.left.as_ref(), max_path_sum);
            let right_sum = Self::dfs(curr_node.right.as_ref(), max_path_sum);
            let curr_sum = curr_node.val + left_sum.max(0) + right_sum.max(0);

            *max_path_sum = (*max_path_sum).max(curr_sum);

            return curr_node.val + left_sum.max(right_sum).max(0);
        }

        0
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_path_sum = i32::MIN;

        Self::dfs(root.as_ref(), &mut max_path_sum);

        max_path_sum
    }
}
