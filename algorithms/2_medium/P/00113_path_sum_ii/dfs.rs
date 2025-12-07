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
    fn dfs(
        res: &mut Vec<Vec<i32>>,
        temp: &mut Vec<i32>,
        curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
        target_sum: i32,
        mut curr_sum: i32,
    ) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            curr_sum += curr_node.val;
            temp.push(curr_node.val);

            if curr_node.left.is_none() && curr_node.right.is_none() {
                if curr_sum == target_sum {
                    res.push(temp.clone());
                }
            }

            Self::dfs(res, temp, curr_node.left.as_ref(), target_sum, curr_sum);
            Self::dfs(res, temp, curr_node.right.as_ref(), target_sum, curr_sum);

            temp.pop();
        }        
    }

    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut temp: Vec<i32> = Vec::new();
        Self::dfs(&mut res, &mut temp, root.as_ref(), target_sum, 0);

        res
    }
}
