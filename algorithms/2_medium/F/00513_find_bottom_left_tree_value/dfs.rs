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
        curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
        curr_row: i32,
        selected_row: &mut i32,
        selected_left_val: &mut i32,
    ) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            if curr_row > *selected_row {
                *selected_row = curr_row;
                *selected_left_val = curr_node.val;
            }

            Self::dfs(curr_node.left.as_ref(), curr_row + 1, selected_row, selected_left_val);
            Self::dfs(curr_node.right.as_ref(), curr_row + 1, selected_row, selected_left_val);
        }
    }
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut selected_row = -1_i32;
        let mut selected_left_val = -1_i32;

        Self::dfs(root.as_ref(), 0_i32, &mut selected_row, &mut selected_left_val);

        selected_left_val
    }
}
