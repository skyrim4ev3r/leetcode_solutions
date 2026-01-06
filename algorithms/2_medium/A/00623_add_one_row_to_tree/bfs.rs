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
use std::collections::VecDeque;
impl Solution {
    pub fn add_one_row(root_rc_opt: Option<Rc<RefCell<TreeNode>>>, val: i32, depth: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if depth == 1 {
            let node =  Rc::new(RefCell::new(TreeNode::new(val)));
            node.borrow_mut().left = root_rc_opt;
            return Some(node);
        }

        if let Some(root_rc) = root_rc_opt {
            let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
            q.push_back(root_rc.clone());
            let mut curr_level = 1_i32;

            while !q.is_empty() {
                if curr_level == depth - 1 {
                    while let Some(mut old_node) = q.pop_front() {
                        let node_l = Rc::new(RefCell::new(TreeNode::new(val)));
                        node_l.borrow_mut().left = old_node.borrow_mut().left.take();
                        old_node.borrow_mut().left = Some(node_l);

                        let node_r = Rc::new(RefCell::new(TreeNode::new(val)));
                        node_r.borrow_mut().right = old_node.borrow_mut().right.take();
                        old_node.borrow_mut().right = Some(node_r);
                    }

                    return Some(root_rc);
                }

                let curr_len = q.len();

                for _ in 0..curr_len {
                    let mut old_node = q.pop_front().unwrap();

                    if let Some(left) = old_node.borrow().left.as_ref() {
                        q.push_back(left.clone());
                    }

                    if let Some(right) = old_node.borrow().right.as_ref() {
                        q.push_back(right.clone());
                    }
                }

                curr_level += 1;
            }
        }

        None
    }
}
