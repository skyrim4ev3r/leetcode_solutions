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
use std::collections::HashSet;
use std::rc::Rc;
use std::cell::RefCell;

struct FindElements {
    values: HashSet<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindElements {

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut values: HashSet<i32> = HashSet::new();

        Self::dfs(root.as_ref(), 0_i32, &mut values);

        Self {
            values
        }
    }

    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, value: i32, values: &mut HashSet<i32>) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            values.insert(value);
            Self::dfs(curr_node.left.as_ref(), 2 * value + 1, values);
            Self::dfs(curr_node.right.as_ref(), 2 * value + 2, values);
        }
    }

    fn find(&self, target: i32) -> bool {
        self.values.contains(&target)
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * let obj = FindElements::new(root);
 * let ret_1: bool = obj.find(target);
 */
