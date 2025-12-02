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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, sum: &mut i32, curr_bin: &mut i32) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            *curr_bin = *curr_bin << 1;
            *curr_bin |= curr_node.val;

            if curr_node.left.is_none() && curr_node.right.is_none() {
                *sum += *curr_bin;
            } else {
                Self::dfs(curr_node.left.as_ref(), sum, curr_bin);
                Self::dfs(curr_node.right.as_ref(), sum, curr_bin);
            }

            *curr_bin = *curr_bin >> 1;
        }
    }

    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sum = 0_i32;
        let mut curr_bin = 0_i32;

        Self::dfs(root.as_ref(), &mut sum, &mut curr_bin);

        sum
    }
}
