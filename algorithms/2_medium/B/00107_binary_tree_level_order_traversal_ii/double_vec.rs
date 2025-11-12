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
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        if root.is_none() {
            return res;
        }

        let mut v1: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        let mut v2: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        v1.push(root.unwrap());

        while !v1.is_empty() {
            let mut tmp: Vec<i32> = Vec::new();

            for node_rc in v1.into_iter() {
                let node = (*node_rc).borrow();
                tmp.push((*node).val);
                if let Some(ref left_ref) = (*node).left {
                    v2.push((*left_ref).clone());
                }

                if let Some(ref right_ref) = (*node).right {
                    v2.push((*right_ref).clone());
                }
                
            }

            res.push(tmp);
            v1 = Vec::new();
            std::mem::swap(&mut v1,&mut v2);
        }

        res.reverse();
 
        res
    }
}
