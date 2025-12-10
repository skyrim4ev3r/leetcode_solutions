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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, is_left_child: bool) -> i32 {
        if let Some(curr_rc) = curr_rc_opt {
            let mut sum = 0_i32;
            let curr = curr_rc.borrow();

            if is_left_child && curr.left.is_none() && curr.right.is_none() {
                sum += curr.val;
            }

            sum += Self::dfs(curr.left.as_ref(), true);
            sum += Self::dfs(curr.right.as_ref(), false);

            return sum;
        }

        0
    }

    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root.as_ref(), false)
    }
}
