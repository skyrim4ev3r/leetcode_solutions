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
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut stack_a : Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        let mut stack_b: Vec<Rc<RefCell<TreeNode>>> = Vec::new();

        stack_a.push(root.as_ref().unwrap().clone());
        let mut max_level = 1_i32;
        let mut curr_level = 1_i32;
        let mut max_level_sum = i32::MIN;

        while !stack_a.is_empty() {
            let mut curr_level_sum = 0_i32;

            while let Some(node_rc) = stack_a.pop() {
                let node = node_rc.borrow();

                if let Some(left) = node.left.as_ref() {
                    stack_b.push(left.clone());
                }

                if let Some(right) = node.right.as_ref() {
                    stack_b.push(right.clone());
                }

                curr_level_sum +=  node.val;
            }

            if curr_level_sum > max_level_sum {
                max_level_sum = curr_level_sum;
                max_level = curr_level; 
            }

            std::mem::swap(&mut stack_a, &mut stack_b);
            curr_level += 1;
        }

        max_level
    }
}
