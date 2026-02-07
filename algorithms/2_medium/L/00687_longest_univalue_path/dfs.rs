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
    fn dfs(
        curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
        parent_val: i32,
        max_path: &mut i32,
    ) -> i32 {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            let left_child_path = Self::dfs(curr.left.as_ref(), curr.val, max_path);
            let right_child_path = Self::dfs(curr.right.as_ref(), curr.val, max_path);
            *max_path = (*max_path).max(1 + left_child_path + right_child_path);

            if curr.val == parent_val {
                return 1 + left_child_path.max(right_child_path);
            } else {
                return 0;
            }
        }

        0
    }

    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut max_path = 0_i32;
        Self::dfs(root.as_ref(), 0, &mut max_path);
        let max_path_edges = max_path - 1;

        max_path_edges
    }
}
