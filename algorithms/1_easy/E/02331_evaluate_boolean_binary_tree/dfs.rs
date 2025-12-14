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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            match curr.val {
                0 => return false,
                1 => return true,
                2 => return Self::dfs(curr.left.as_ref()) || Self::dfs(curr.right.as_ref()),
                _ => return Self::dfs(curr.left.as_ref()) && Self::dfs(curr.right.as_ref()),
            }
        }

        false
    }
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::dfs(root.as_ref())
    }
}
