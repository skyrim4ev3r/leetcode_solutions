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
    fn clean_up_leaves(curr_node_opt: Option<Rc<RefCell<TreeNode>>>, target: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = curr_node_opt {

            {
                let mut node_ref = node.borrow_mut();

                node_ref.left = Self::clean_up_leaves(node_ref.left.take(), target);
                node_ref.right = Self::clean_up_leaves(node_ref.right.take(), target);

                if node_ref.val == target && node_ref.left.is_none() && node_ref.right.is_none() {
                    return None;
                }
            }

            return Some(node);
        }

        None
    }

    pub fn remove_leaf_nodes(root: Option<Rc<RefCell<TreeNode>>>, target: i32) -> Option<Rc<RefCell<TreeNode>>> {
        Self::clean_up_leaves(root, target)
    }
}
