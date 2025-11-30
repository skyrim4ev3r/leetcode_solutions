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
        curr_node_rc_opt: Option<Rc<RefCell<TreeNode>>>,
        prev: Option<Rc<RefCell<TreeNode>>>
    ) ->  Option<Rc<RefCell<TreeNode>>> {
        if curr_node_rc_opt.is_none() {
            return prev;
        }

        let curr_node_rc = curr_node_rc_opt.unwrap();
        let left = curr_node_rc.borrow_mut().left.take();
        let right = curr_node_rc.borrow_mut().right.take();

        curr_node_rc.borrow_mut().right = Self::dfs(right, prev);
        Self::dfs(left, Some(curr_node_rc))
    }

    pub fn increasing_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(root, None)
    }
}
