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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> (i32, i32) {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();
            let (l_max1, l_max2) = Self::dfs(curr.left.as_ref());
            let (r_max1, r_max2) = Self::dfs(curr.right.as_ref());

            return (
                l_max2 + r_max2 + curr.val,
                l_max1.max(l_max2) + r_max1.max(r_max2)
            );
        }

        (0, 0)
    }

    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let res = Self::dfs(root.as_ref());

        res.0.max(res.1)
    }
}
