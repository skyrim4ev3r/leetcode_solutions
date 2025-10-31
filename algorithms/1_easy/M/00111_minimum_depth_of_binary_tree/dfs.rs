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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, curr_depth: i32, min_depth: &mut i32) {
        if curr_depth < *min_depth && let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            // Check if the current node is a leaf node
            if curr_node.left.is_none() && curr_node.right.is_none() {
                *min_depth = (*min_depth).min(curr_depth);
            } else {
                // Only call dfs for children if the current node is not a leaf
                Self::dfs(curr_node.left.as_ref(), curr_depth + 1, min_depth);
                Self::dfs(curr_node.right.as_ref(), curr_depth + 1, min_depth);
            }
        }
    }

    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut min_depth = i32::MAX;

        Self::dfs(root.as_ref(), 1, &mut min_depth);

        return min_depth;
    }
}
