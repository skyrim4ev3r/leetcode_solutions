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
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut level = 1_i32;
        let mut max_sum = i32::MIN;
        let mut max_sum_level = 1;
        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        q.push_back(root.unwrap());

        while !q.is_empty() {
            let curr_len = q.len();
            let mut curr_sum = 0_i32;

            for _ in 0..curr_len {
                let node_rc = q.pop_front().unwrap();
                let node = node_rc.borrow();

                curr_sum += node.val;

                if let Some(left) = node.left.as_ref() {
                    q.push_back(left.clone());
                }

                if let Some(right) = node.right.as_ref() {
                    q.push_back(right.clone());
                }
            }

            if curr_sum > max_sum {
                max_sum = curr_sum;
                max_sum_level = level;
            }

            level += 1;
        }

        max_sum_level
    }
}
