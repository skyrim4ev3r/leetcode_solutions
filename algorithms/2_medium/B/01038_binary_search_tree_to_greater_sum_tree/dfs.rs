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
    fn dfs(curr: &mut Option<Rc<RefCell<TreeNode>>>, sum: &mut i32) {
        if let Some(rc_curr) = curr {
            let mut ref_curr = rc_curr.borrow_mut();
            Self::dfs(&mut ref_curr.right, sum);
            *sum += ref_curr.val;
            ref_curr.val = *sum;
            Self::dfs(&mut ref_curr.left, sum);
        }
    }

    pub fn bst_to_gst(mut root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(&mut root, &mut 0);

        root
    }
}
