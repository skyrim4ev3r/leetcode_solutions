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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, curr_sum: i32) -> i32 {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            if curr.left.is_none() && curr.right.is_none() {
                return curr_sum * 10 + curr.val;
            }

            return Self::dfs(curr.left.as_ref(), curr_sum * 10 + curr.val) +
                   Self::dfs(curr.right.as_ref(), curr_sum * 10 + curr.val);
        }

        0_i32
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root.as_ref(), 0_i32)
    }
}
