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
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        queue.push_back(root.unwrap());
        let mut res: Vec<f64> = Vec::new();

        while !queue.is_empty() {
            let n = queue.len();
            let mut sum = 0_f64;

            for _ in 0..n {
                let curr_rc = queue.pop_front().unwrap();
                let curr = curr_rc.borrow();
                sum += curr.val as f64;

                if let Some(ref left) = curr.left {
                    queue.push_back(left.clone());
                }
                if let Some(ref right) = curr.right {
                    queue.push_back(right.clone());
                }
            }

            res.push(sum / n as f64);
        }

        res
    }
}
