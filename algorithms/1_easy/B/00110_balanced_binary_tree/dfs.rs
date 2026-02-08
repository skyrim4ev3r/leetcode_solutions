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
    fn dfs_height(curr_rs_opt: Option<&Rc<RefCell<TreeNode>>>, is_balanced: &mut bool) -> i32 {
        if ! *is_balanced {
            return 0;
        }

        if let Some(curr_rc) = curr_rs_opt {
            let curr = curr_rc.borrow();

            let left_height = Self::dfs_height(curr.left.as_ref(), is_balanced);
            let right_height = Self::dfs_height(curr.right.as_ref(), is_balanced);

            if (left_height - right_height).abs() > 1 {
                *is_balanced = false;
            }

            return 1 + left_height.max(right_height);
        }

        0
    }
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut is_balanced = true;

        Self::dfs_height(root.as_ref(), &mut is_balanced);

        is_balanced
    }
}
