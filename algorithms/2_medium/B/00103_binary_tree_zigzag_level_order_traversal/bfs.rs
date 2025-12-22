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
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {
            return Vec::new();
        }

        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        q.push_back(root.as_ref().unwrap().clone());
        let mut flip_flop = false;
        let mut res: Vec<Vec<i32>> = Vec::new();

        while !q.is_empty() {
            let len = q.len();
            let mut temp: Vec<i32> = Vec::with_capacity(len);

            for _ in 0..len{
                let node_rc = q.pop_front().unwrap();
                let node = node_rc.borrow();
                temp.push(node.val);

                if let Some(left_ref) = node.left.as_ref() {
                    q.push_back(left_ref.clone());
                }

                if let Some(right_ref) = node.right.as_ref() {
                    q.push_back(right_ref.clone());
                }
            }

            if flip_flop {
                temp.reverse();
            }

            res.push(temp);
            flip_flop = !flip_flop;
        }

        res
    }
}
