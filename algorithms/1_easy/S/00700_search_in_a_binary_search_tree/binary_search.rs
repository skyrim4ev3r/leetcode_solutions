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
use std::cmp::Ordering;
impl Solution {
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        let mut curr_rc_opt = root.clone();

        while let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            match curr.val.cmp(&val) {
                Ordering::Equal => return Some(curr_rc.clone()),
                Ordering::Less => curr_rc_opt = curr.right.clone(),
                Ordering::Greater => curr_rc_opt = curr.left.clone(),
            }
        }

        None
    }
}
