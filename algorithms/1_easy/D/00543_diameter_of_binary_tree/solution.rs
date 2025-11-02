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
    fn diameter_of_binary_tree_helper(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, max_path: &mut i32) -> i32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            let left_path_len = Self::diameter_of_binary_tree_helper(curr_node.left.as_ref(), max_path);
            let right_path_len = Self::diameter_of_binary_tree_helper(curr_node.right.as_ref(), max_path);

            let curr_node_path = 1 + left_path_len + right_path_len;

            *max_path = (*max_path).max(curr_node_path);

            return 1 + left_path_len.max(right_path_len);
        }

        0
    }

    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_path = 0_i32;

        Self::diameter_of_binary_tree_helper(root.as_ref(), &mut max_path);

        // Subtract 1 because the diameter is defined as the number of edges, 
        // which is one less than the number of nodes in the longest path.
        max_path - 1
    }
}
