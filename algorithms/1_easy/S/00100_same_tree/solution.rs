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
    fn is_same_tree_helper(p_rc_opt: Option<&Rc<RefCell<TreeNode>>>, q_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> bool {
         match (p_rc_opt, q_rc_opt) {
            (Some(p_rc), Some(q_rc)) => {
                let p = p_rc.borrow();
                let q = q_rc.borrow();

                p.val == q.val && 
                Self::is_same_tree_helper(p.left.as_ref(), q.left.as_ref()) &&
                Self::is_same_tree_helper(p.right.as_ref(), q.right.as_ref())
            },
            (None, None) => true,
            _ => false,
        }
    }

    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
       Self::is_same_tree_helper(p.as_ref(), q.as_ref())
    }
}
