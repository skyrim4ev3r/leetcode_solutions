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
use std::collections::VecDeque;
impl Solution {
    pub fn replace_value_in_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut q: VecDeque<(Rc<RefCell<TreeNode>>, i32)> = VecDeque::new();
        q.push_back((root.clone().unwrap(), 0));

        while !q.is_empty() {
            let len = q.len();
            let mut level_sum = 0_i32;

            for (node_rc, _) in q.iter() {
                level_sum += node_rc.borrow().val;
            }

            for _ in 0..len {
                let (node_rc, bruh_sum) = q.pop_front().unwrap();
                let curr_val = node_rc.borrow().val;
                node_rc.borrow_mut().val = level_sum - curr_val - bruh_sum;
                let node = node_rc.borrow();
                let right_val = if let Some(r) = node.right.as_ref() { r.borrow().val } else { 0 };
                let left_val = if let Some(l) = node.left.as_ref() { l.borrow().val } else { 0 };

                if let Some(r) = node.right.as_ref() {
                    q.push_back((r.clone(), left_val));
                }

                if let Some(l) = node.left.as_ref() {
                    q.push_back((l.clone(), right_val));
                }
            }
        }

        root
    }
}
