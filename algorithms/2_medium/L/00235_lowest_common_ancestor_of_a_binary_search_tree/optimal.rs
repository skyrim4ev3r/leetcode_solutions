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
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        debug_assert!(p.is_some() && q.is_some() && root.is_some() && p.as_ref().unwrap().borrow().val != q.as_ref().unwrap().borrow().val);
        let p_val = p.as_ref().unwrap().borrow().val;
        let q_val = q.as_ref().unwrap().borrow().val;

        let mut curr_rc_opt = root;

        while let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();
            let curr_val = curr.val;

            if curr_val < p_val && curr_val < q_val {
                curr_rc_opt = curr.right.clone();
            } else if (curr_val > p_val && curr_val > q_val) {
                curr_rc_opt = curr.left.clone();
            } else {
                return Some(curr_rc.clone());
            }
        }

        unreachable!("invalid input")
    }
}
