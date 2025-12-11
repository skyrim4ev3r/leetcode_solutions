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
        curr_row: usize,
        max_rows: &mut Vec<i32>,
    ) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            if curr_row >= max_rows.len() {
                max_rows.push(curr_node.val);
            } else {
                max_rows[curr_row] = max_rows[curr_row].max(curr_node.val);
            }

            Self::dfs(curr_node.left.as_ref(), curr_row + 1, max_rows);
            Self::dfs(curr_node.right.as_ref(), curr_row + 1, max_rows);
        }
    }

    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut max_rows: Vec<i32> = Vec::new();

        Self::dfs(root.as_ref(), 0, &mut max_rows);

        max_rows
    }
}
