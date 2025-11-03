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
use std::collections::HashSet;
impl Solution {
    pub fn find_target(mut root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        let mut set: HashSet<i32> = HashSet::new();
        let mut stack: Vec<Rc<RefCell<TreeNode>>> = Vec::new();

        if let Some(node) = root {
            stack.push(node);
        }

        while let Some(curr_node_rc) = stack.pop() {
            
            let curr_node = curr_node_rc.borrow();

            if set.contains(&(k - curr_node.val)) {
                return true;
            }

            set.insert(curr_node.val);

            if let Some(ref right) = curr_node.right {
                stack.push(Rc::clone(right));
            }

            if let Some(ref left) = curr_node.left {
                stack.push(Rc::clone(left));
            }
           
        }

        false
    }
}
