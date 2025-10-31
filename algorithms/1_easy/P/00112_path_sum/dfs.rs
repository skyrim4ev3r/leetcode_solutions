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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, mut curr_sum: i32, target_sum: i32) -> bool {

        match curr_node_rc_opt {
            Some(curr_node_rc) => {
                let curr_node = curr_node_rc.borrow();
                curr_sum += curr_node.val;
                let is_leaf = (curr_node.left.is_none()) && (curr_node.right.is_none());

                (is_leaf && curr_sum == target_sum) || 
                Self::dfs(curr_node.left.as_ref(), curr_sum, target_sum) ||
                Self::dfs(curr_node.right.as_ref(), curr_sum, target_sum)
            },
            None => false
        }        
    }

    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        Self::dfs(root.as_ref(), 0, target_sum)
    }
}
