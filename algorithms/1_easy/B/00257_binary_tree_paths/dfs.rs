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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, res: &mut Vec<String>, temp: &mut Vec<String>) {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = curr_rc.borrow();

            temp.push(curr.val.to_string());

            if curr.left.is_none() && curr.right.is_none() {
                res.push(temp.join("->"));
            } else {
                Self::dfs(curr.left.as_ref(), res, temp);
                Self::dfs(curr.right.as_ref(), res, temp);
            }

            temp.pop();
        }
    }

    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut temp: Vec<String> = Vec::new();

        Self::dfs(root.as_ref(), &mut res, &mut temp);

        res
    }
}
