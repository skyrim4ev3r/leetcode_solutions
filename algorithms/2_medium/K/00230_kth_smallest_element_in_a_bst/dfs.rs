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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, k: i32, count: &mut i32, res: &mut i32) {
        if *count > k {
            return;
        }

        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            Self::dfs(curr.left.as_ref(), k, count, res);

            *count += 1;

            if *count == k {
                *res = curr.val;
            }

            Self::dfs(curr.right.as_ref(), k, count, res);
        }
    }

    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut res = 0_i32;
        let mut count = 0_i32;

        Self::dfs(root.as_ref(), k, &mut count, &mut res);

        res
    }
}
