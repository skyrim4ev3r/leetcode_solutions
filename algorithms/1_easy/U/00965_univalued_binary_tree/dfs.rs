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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, root_val: i32) -> bool {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            if curr.val != root_val {
                return false;
            }

            return Self::dfs(curr.left.as_ref(), root_val) &&
                   Self::dfs(curr.right.as_ref(), root_val);
        }

        true
    }
    pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let root_val = root.as_ref().unwrap().borrow().val;

        Self::dfs(root.as_ref(), root_val) 
    }
}
