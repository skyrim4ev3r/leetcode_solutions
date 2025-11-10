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
    fn zig_zag_helper_search(curr: Option<&Rc<RefCell<TreeNode>>>, curr_zig_zag_len: i32, should_call_left: bool, max_zig_zag_len: &mut i32) {
        if let Some(node_rc) = curr {
            *max_zig_zag_len = (*max_zig_zag_len).max(curr_zig_zag_len);
            let node = node_rc.borrow();

            if should_call_left {
                Self::zig_zag_helper_search(node.left.as_ref(), curr_zig_zag_len + 1, !should_call_left, max_zig_zag_len);
                Self::zig_zag_helper_search(node.right.as_ref(), 1, true, max_zig_zag_len);
            } else {
                Self::zig_zag_helper_search(node.left.as_ref(), 1, false, max_zig_zag_len);
                Self::zig_zag_helper_search(node.right.as_ref(), curr_zig_zag_len + 1, !should_call_left, max_zig_zag_len);
            }
        }
    }

    pub fn longest_zig_zag(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_zig_zag_len = 0_i32;

        Self::zig_zag_helper_search(root.as_ref(), 0, false, &mut max_zig_zag_len);

        max_zig_zag_len
    }
}
