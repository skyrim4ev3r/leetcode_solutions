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
    pub fn reverse_odd_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut vec_a: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        let mut vec_b: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        let mut curr_level = 0_i32;

        vec_a.push(root.as_ref().unwrap().clone());

        while !vec_a.is_empty() {
            if ((curr_level & 1) == 1) {
                let mut left = 0_usize;
                let mut right = vec_a.len() - 1;

                while left < right {
                    let temp = vec_a[left].borrow().val;
                    vec_a[left].borrow_mut().val = vec_a[right].borrow().val;
                    vec_a[right].borrow_mut().val= temp;
                    right -= 1;
                    left += 1;
                }
            }

            for node in vec_a.into_iter() {
                if let Some(ref left) = node.borrow().left {
                    vec_b.push(left.clone());
                }

                if let Some(ref right) = node.borrow().right {
                    vec_b.push(right.clone());
                }
            }

            vec_a = vec_b;
            vec_b = Vec::new();
            curr_level += 1;
        }

        root
    }
}
