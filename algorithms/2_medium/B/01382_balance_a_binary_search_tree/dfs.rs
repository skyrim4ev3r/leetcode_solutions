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
    fn dfs_tree_to_vec(
        curr_rc_opt: Option<Rc<RefCell<TreeNode>>>,
        res: &mut Vec<Rc<RefCell<TreeNode>>>,
    ) {
        if let Some(curr_rc) = curr_rc_opt {
            let (left, right) = {
                let mut curr = curr_rc.borrow_mut();
                (curr.left.take(), curr.right.take())
            };
            

            Self::dfs_tree_to_vec(left, res);
            res.push(curr_rc);
            Self::dfs_tree_to_vec(right, res);
        }
    }

    fn dfs_vec_to_balance_tree(
        res: &Vec<Rc<RefCell<TreeNode>>>,
        left: usize,
        right: usize,
        len: usize,
    ) -> Option<Rc<RefCell<TreeNode>>>  {
        if right >= len || left >= len || left > right {
            return None;
        }

        let mid = left + (right - left) / 2;
        let node_rc = res[mid].clone();

        {
            let mut node = node_rc.borrow_mut();
            node.left = Self::dfs_vec_to_balance_tree(res, left, mid - 1, len);
            node.right = Self::dfs_vec_to_balance_tree(res, mid + 1, right, len);
        }

        Some(node_rc)
    }
    pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut res: Vec<Rc<RefCell<TreeNode>>> = Vec::new();

        Self::dfs_tree_to_vec(root, &mut res);

        let len = res.len();
        let left = 0;
        let right = len - 1;

        Self::dfs_vec_to_balance_tree(&res, left, right, len)
    }
}
