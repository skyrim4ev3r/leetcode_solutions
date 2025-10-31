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
    fn dfs(curr_node_rc_opr: Option<&Rc<RefCell<TreeNode>>>, max_level: &mut i32, curr_level: i32) {
        if let Some(curr_node_rc) = curr_node_rc_opr {
            *max_level = (*max_level).max(curr_level);

            let curr_node = curr_node_rc.borrow();

            Self::dfs(curr_node.left.as_ref(), max_level, curr_level + 1);
            Self::dfs(curr_node.right.as_ref(), max_level, curr_level + 1);
        }
    }

    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_level = 0_i32;

        Self::dfs(root.as_ref(), &mut max_level, 1);

        return max_level;
    }
}
