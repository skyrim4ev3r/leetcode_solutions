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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, min_val: i64, max_val: i64) -> bool {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            let curr_val = curr_node.val as i64;

            return curr_val > min_val && curr_val < max_val &&
                    Self::dfs(curr_node.left.as_ref(), min_val, curr_val) &&
                    Self::dfs(curr_node.right.as_ref(), curr_val, max_val);
        }

        true 
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::dfs(root.as_ref(), i64::MIN, i64::MAX)
    }
}
