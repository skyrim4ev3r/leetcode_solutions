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
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, min1: &mut i32, min2: &mut i32) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            if *min1 == -1 || curr_node.val < *min1 {
                *min2 = *min1;
                *min1 = curr_node.val;
            } else if curr_node.val != *min1 {
                if *min2 == -1 {
                    *min2 = curr_node.val;
                } else {
                    *min2 = (*min2).min(curr_node.val);
                }
            }

            Self::dfs(curr_node.left.as_ref(), min1, min2);
            Self::dfs(curr_node.right.as_ref(), min1, min2);
        }
    }

    pub fn find_second_minimum_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut min1 = -1_i32;
        let mut min2 = -1_i32;

        Self::dfs(root.as_ref(), &mut min1, &mut min2);

        min2
    }
}
