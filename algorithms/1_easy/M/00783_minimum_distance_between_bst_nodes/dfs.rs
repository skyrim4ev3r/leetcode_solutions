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
    fn dfs(curr_rc: &Rc<RefCell<TreeNode>>, min_diff: &mut i32) -> (i32, i32) {
        let curr = curr_rc.borrow();
        let val = curr.val;
        let mut min = val;
        let mut max = val;

        if let Some(ref left) = curr.left {
            let left_res = Self::dfs(left, min_diff);
            *min_diff = (*min_diff).min(val - left_res.1);
            min = left_res.0;
        }

        if let Some(ref right) = curr.right {
            let right_res = Self::dfs(right, min_diff);
            *min_diff = (*min_diff).min(right_res.0 - val);
            max = right_res.1;
        }

        (min, max)
    }

    pub fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut min_diff = i32::MAX;

        Self::dfs(root.as_ref().unwrap(), &mut min_diff);

        min_diff
    }
}
