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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, curr_level: i32, max_level: &mut i32, sum: &mut i32) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            if (curr_level > *max_level) {
                *max_level = curr_level;
                *sum = curr_node.val;
            } else if (curr_level == *max_level) {
                *sum += curr_node.val;
            }

            Self::dfs(curr_node.left.as_ref(), curr_level + 1, max_level, sum);
            Self::dfs(curr_node.right.as_ref(), curr_level + 1, max_level, sum);
        }
    }
    pub fn deepest_leaves_sum(mut root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sum = 0_i32;
        let mut max_level = -1_i32;

        Self::dfs(root.as_ref(),0, &mut max_level, &mut sum);

        sum
    }
}
