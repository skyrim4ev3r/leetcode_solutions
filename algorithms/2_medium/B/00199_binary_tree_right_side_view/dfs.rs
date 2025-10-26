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
    fn dfs(res: &mut Vec<i32>, curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, depth: usize) {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            if depth >= res.len() {
                res.push(curr.val);
            } else {
                res[depth] = curr.val;
            }

            Self::dfs(res, curr.left.as_ref(), depth + 1);
            Self::dfs(res, curr.right.as_ref(), depth + 1);
        }
    }

    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        Self::dfs(&mut res, root.as_ref(), 0);

        res
    }
}
