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
    fn dfs(curr_node_opt: Option<&Rc<RefCell<TreeNode>>>, mut max_val: i32) -> i32 {
        if (curr_node_opt.is_none()) {
            return 0;
        }

        let curr_node = curr_node_opt.unwrap().borrow();

        let mut sum = 0;

        if max_val <= curr_node.val {
            sum = 1;
            max_val = curr_node.val;
        }

        sum += Self::dfs(curr_node.left.as_ref(), max_val);
        sum += Self::dfs(curr_node.right.as_ref(), max_val);

        sum
    }
    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let max_val = i32::MIN;

        Self::dfs(root.as_ref(), max_val)
    }
}
