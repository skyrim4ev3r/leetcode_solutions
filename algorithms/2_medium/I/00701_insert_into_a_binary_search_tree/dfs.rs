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
    fn dfs_insert(curr_rc: &Rc<RefCell<TreeNode>>, val: i32) {
        let mut curr = curr_rc.borrow_mut();
        if curr.val > val {
            if curr.left.is_some() {
                Self::dfs_insert(curr.left.as_ref().unwrap(), val);
            } else {
                curr.left = Some(Rc::new(RefCell::new(TreeNode::new(val))));
            }
        } else if curr.val < val {
            if curr.right.is_some() {
                Self::dfs_insert(curr.right.as_ref().unwrap(), val);
            } else {
                curr.right = Some(Rc::new(RefCell::new(TreeNode::new(val))));
            }
        }
    }

    pub fn insert_into_bst(
        root_rc_opt: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match root_rc_opt {
            Some(root_rc) => {
                Self::dfs_insert(&root_rc, val);
                Some(root_rc)
            },
            None => Some(Rc::new(RefCell::new(TreeNode::new(val)))),
        }
    }
}
