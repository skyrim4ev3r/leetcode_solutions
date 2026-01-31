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
        curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
        p: &Rc<RefCell<TreeNode>>,
        q: &Rc<RefCell<TreeNode>>,
        res: &mut Option<Rc<RefCell<TreeNode>>>
    ) -> (bool, bool) {
        if curr_rc_opt.is_none() || res.is_some() {
            return (false, false);
        }

        let curr_rc = curr_rc_opt.unwrap();
        let curr = curr_rc.borrow();
        let left_res = Self::dfs(curr.left.as_ref(), p, q, res);
        let right_res = Self::dfs(curr.right.as_ref(), p, q, res);
        let found_p = left_res.0 || right_res.0 || curr_rc == p;
        let found_q = left_res.1 || right_res.1 || curr_rc == q;

        if res.is_none() && found_p && found_q {
            *res = Some(curr_rc.clone());
        }

        (found_p, found_q)
    }

    pub fn lowest_common_ancestor(root: Option<Rc<RefCell<TreeNode>>>, p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut res: Option<Rc<RefCell<TreeNode>>> = None;

        Self::dfs(root.as_ref(), &p.unwrap(), &q.unwrap(), &mut res);

        res
    }
}
