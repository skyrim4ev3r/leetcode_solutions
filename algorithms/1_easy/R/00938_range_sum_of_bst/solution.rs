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
    fn range_sum_bst_recursive(curr_node_opt:  Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {

        if let Some(curr_node_rc) = curr_node_opt{
            let mut sum = 0_i32;

            let curr_node = curr_node_rc.borrow();

            if curr_node.val >= low && curr_node.val <= high {
                sum += curr_node.val;
            }

            sum += Self::range_sum_bst_recursive(curr_node.left.clone(), low, high);
            sum += Self::range_sum_bst_recursive(curr_node.right.clone(), low, high);

            return sum;
        }

        0
    }

    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        Self::range_sum_bst_recursive(root, low, high)
    }
}
