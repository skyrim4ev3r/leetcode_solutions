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
    fn dfs(curr_rc: &Rc<RefCell<TreeNode>>) -> (i32, i32, Option<i32>) {
        let curr = curr_rc.borrow();
        let val = curr.val;
        let mut max = curr.val;
        let mut min = curr.val;
        let mut min_diff_opt: Option<i32> = None;

        if let Some(left) = curr.left.as_ref() {
            let (min_left, max_left, min_diff_left_opt) = Self::dfs(left);
            min = min_left;
            min_diff_opt = match min_diff_left_opt {
                None => Some(val - max_left),
                Some(x) => Some((val - max_left).min(x)),
            };
        }

        if let Some(right) = curr.right.as_ref() {
            let (min_right, max_right, min_diff_right_opt) = Self::dfs(right);
            max = max_right;
            min_diff_opt = match (min_diff_opt, min_diff_right_opt) {
                (Some(x), Some(y)) => Some((min_right - val).min(x).min(y)),
                (Some(x), None) => Some((min_right - val).min(x)),
                (None, Some(y)) => Some((min_right - val).min(y)),
                (None, None) => Some(min_right - val),
            };
        }

        (min, max, min_diff_opt)
    }

    pub fn get_minimum_difference(root_rc_opt: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(root_rc) = root_rc_opt {
            let min_diff_opt = Self::dfs(&root_rc).2;

            match min_diff_opt {
                Some(x) => return x,
                None => unreachable!(),
            };
        }

        unreachable!()
    }
}
