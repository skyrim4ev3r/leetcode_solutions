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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, is_grandpa_even: bool, is_parent_even: bool) -> i32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let mut sum = 0_i32;
            let curr_node = curr_node_rc.borrow();

            if is_grandpa_even {
                sum += curr_node.val;
            }

            let is_curr_node_even = ((curr_node.val % 2) == 0);
            sum += Self::dfs(curr_node.left.as_ref(), is_parent_even, is_curr_node_even);
            sum += Self::dfs(curr_node.right.as_ref(), is_parent_even, is_curr_node_even);

            return sum;
        }

        0_i32
    }

    pub fn sum_even_grandparent(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root.as_ref(), false, false)
    }
}
