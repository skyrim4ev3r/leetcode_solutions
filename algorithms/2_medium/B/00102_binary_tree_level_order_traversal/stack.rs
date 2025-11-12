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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        match root {
            Some(node_rc) => {
                let mut current_level: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
                let mut next_level: Vec<Rc<RefCell<TreeNode>>> = Vec::new();

                current_level.push(node_rc.clone());

                while !current_level.is_empty() {
                    let mut temp: Vec<i32> = Vec::new();

                    for node_rc in current_level {
                        let node = node_rc.borrow();
                        temp.push(node.val);

                        if let Some(ref left_node) = node.left {
                            next_level.push(left_node.clone());
                        }

                        if let Some(ref right_node) = node.right {
                            next_level.push(right_node.clone());
                        }
                    }

                    res.push(temp);
                    current_level = next_level;
                    next_level = Vec::new();
                }

                res
            },
            None => res
        }
    }
}
