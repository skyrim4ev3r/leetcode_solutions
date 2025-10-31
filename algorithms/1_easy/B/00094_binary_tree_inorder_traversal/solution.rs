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

    fn inorder_traversal_helper(res: &mut Vec<i32> ,curr_node_rc_opt: Option<Rc<RefCell<TreeNode>>>) {

        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            Self::inorder_traversal_helper(res, curr_node.left.clone());

            res.push(curr_node.val);
            
            Self::inorder_traversal_helper(res, curr_node.right.clone());
        }
    }

    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        Self::inorder_traversal_helper(&mut res, root);

        res
    }
}
