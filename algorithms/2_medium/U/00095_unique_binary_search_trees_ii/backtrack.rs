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
    fn dfs_copy_tree(
        original_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(original_node_rc) = original_node_rc_opt {
            let original_node = original_node_rc.borrow();
            let mut new_node = TreeNode::new(original_node.val);

            new_node.left = Self::dfs_copy_tree(original_node.left.as_ref());
            new_node.right = Self::dfs_copy_tree(original_node.right.as_ref());

            return Some(Rc::new(RefCell::new(new_node)));
        }

        None
    }

    fn backtrack_generate_trees(left: i32, right: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if left > right {
            return vec![None];
        }

        let mut res: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();

        for i in left..=right {
            let all_right = Self::backtrack_generate_trees(i + 1, right);
            let all_left = Self::backtrack_generate_trees(left, i - 1);

            for ar in all_right.into_iter() {
                for ref_al in all_left.iter() {
                    let al = ref_al.clone();
                    let mut node = TreeNode::new(i);
                    node.left = Self::dfs_copy_tree(al.as_ref());
                    node.right = Self::dfs_copy_tree(ar.as_ref());
                    res.push(Some(Rc::new(RefCell::new(node))));
                }
            }
        }

        res
    }

    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        Self::backtrack_generate_trees(1, n)
    }
}
