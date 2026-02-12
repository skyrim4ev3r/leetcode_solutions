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

use std::cell::RefCell;
use std::rc::Rc;

struct BSTIterator {
    stack: Vec<Rc<RefCell<TreeNode>>>
}

impl BSTIterator {
    #[inline(always)]
    fn push_node_and_all_left_childs(&mut self, mut curr_rc_opt: Option<Rc<RefCell<TreeNode>>>) {
        while let Some(curr_rc) = curr_rc_opt {
            self.stack.push(curr_rc.clone());
            let curr = curr_rc.borrow();
            curr_rc_opt = curr.left.clone();
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut res = Self {
            stack: Vec::new(),
        };

        res.push_node_and_all_left_childs(root);

        res
    }

    fn next(&mut self) -> i32 {
        if let Some(mut node_rc) = self.stack.pop() {
            let node = node_rc.borrow();
            self.push_node_and_all_left_childs(node.right.clone());
            node.val
        } else {
            panic!("should not call next on empty stack!")
        }
    }

    fn has_next(&self) -> bool {
        !self.stack.is_empty()
    }
}
