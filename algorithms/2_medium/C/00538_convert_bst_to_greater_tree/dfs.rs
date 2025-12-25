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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, val: &mut i32) {
        if let Some(curr_rc) = curr_rc_opt {
            let mut curr = curr_rc.borrow_mut();

            Self::dfs(curr.right.as_ref(), val);
            curr.val += *val;
            *val = curr.val;
            Self::dfs(curr.left.as_ref(), val);
        }
    }

    pub fn convert_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut val = 0_i32;
        Self::dfs(root.as_ref(), &mut val);

        root
    }
}
