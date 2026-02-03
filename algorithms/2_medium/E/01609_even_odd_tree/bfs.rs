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
    pub fn is_even_odd_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut curr_level = 0_i32;
        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        q.push_back(root.unwrap());

        while !q.is_empty() {
            let curr_len = q.len();
            let mut prev_val: Option<i32> = None;

            for _ in 0..curr_len {
                let node_rc = q.pop_front().unwrap();
                let node = node_rc.borrow();

                if (curr_level & 1) == (node.val & 1) {
                    return false;
                }
                
                if (curr_level & 1) == 0 {
                    if let Some(val) = prev_val && val >= node.val {
                        return false;
                    }
                } else {
                    if let Some(val) = prev_val && val <= node.val {
                        return false;
                    }
                }

                prev_val = Some(node.val);

                if let Some(left) = node.left.clone() {
                    q.push_back(left);
                }

                if let Some(right) = node.right.clone() {
                    q.push_back(right);
                }
            }

            curr_level += 1;
        }

        true
    }
}
