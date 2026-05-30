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
    fn max_depth_helper(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            return 1 + Self::max_depth_helper(curr_node.left.as_ref()).max(Self::max_depth_helper(curr_node.right.as_ref()));
        }

        0
    }

    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::max_depth_helper(root.as_ref())
    }
}
