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
    fn dfs(curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>, p: &TreeNode, q: &TreeNode) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(curr_rc) = curr_rc_opt {
            let curr = &*curr_rc.borrow();

            if curr == p || curr == q {
                return Some(curr_rc.clone());
            }

            let left = Self::dfs(curr.left.as_ref(), p, q);
            let right = Self::dfs(curr.right.as_ref(), p, q);

            if left.is_some() && right.is_some() {
                return Some(curr_rc.clone());
            }

            return if left.is_some() { left } else { right };
        }

        None
    }

    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let res = Self::dfs(root.as_ref(), &*p.unwrap().borrow(), &*q.unwrap().borrow());
        debug_assert!(res.is_some());
        res
    }
}
