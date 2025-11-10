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
    fn fill_leaf_vector(leaf_vector: &mut Vec<i32>, curr: Option<&Rc<RefCell<TreeNode>>>) {
        if let Some(node_rc) = curr {
            let node = node_rc.borrow();

            Self::fill_leaf_vector(leaf_vector, node.left.as_ref());
            Self::fill_leaf_vector(leaf_vector, node.right.as_ref());

            if node.left.is_none() && node.right.is_none() {
                leaf_vector.push(node.val);
            }
        }
    }

    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut leaf1: Vec<i32> = Vec::new();
        let mut leaf2: Vec<i32> = Vec::new();

        Self::fill_leaf_vector(&mut leaf1, root1.as_ref());
        Self::fill_leaf_vector(&mut leaf2, root2.as_ref());

        leaf1 == leaf2
    }
}
