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
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        if root.is_none() {
            return res;
        }

        let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        queue.push_back(root.unwrap());

        while !queue.is_empty() {
            let len = queue.len();
            let mut temp: Vec<i32> = Vec::new();

            for i in 0..len {
                let node_rc = queue.pop_front().unwrap();
                let node = (*node_rc).borrow();
                temp.push((*node).val);

                if let Some(ref left_ref) = (*node).left {
                    queue.push_back((*left_ref).clone());
                }
                if let Some(ref right_ref) = (*node).right {
                    queue.push_back((*right_ref).clone());
                }
                
            }

            res.push(temp);
        }

        res.reverse();
 
        res
    }
}
