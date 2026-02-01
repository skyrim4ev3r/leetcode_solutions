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
        max_diff: &mut i32
    ) -> Option<(i32, i32)> {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();
            let curr_val = curr.val;
            let mut curr_max = curr_val;
            let mut curr_min = curr_val;

            if let Some((left_min, left_max)) = Self::dfs(curr.left.as_ref(), max_diff) {
                curr_min = curr_min.min(left_min);
                curr_max = curr_max.max(left_max);
            }

            if let Some((right_min, right_max)) = Self::dfs(curr.right.as_ref(), max_diff) {
                curr_min = curr_min.min(right_min);
                curr_max = curr_max.max(right_max);
            }

            *max_diff = (*max_diff).max(curr_val - curr_min).max(curr_max - curr_val);

            return Some((curr_min, curr_max));
        }

        None
    }

    pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_diff = i32::MIN;

        Self::dfs(root.as_ref(), &mut max_diff);

        max_diff
    }
}
