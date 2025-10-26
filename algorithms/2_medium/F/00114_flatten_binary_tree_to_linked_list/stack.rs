use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn flatten(root_rc_opt: &mut Option<Rc<RefCell<TreeNode>>>) {
        if let Some(root_rc) = root_rc_opt {
            let mut stack: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
            stack.push(root_rc.clone());

            let mut prev_rc_opt: Option<Rc<RefCell<TreeNode>>> = None;

            while let Some(node_rc) = stack.pop() {
                let mut node = node_rc.borrow_mut();
                let left_rc_opt = node.left.take();
                let right_rc_opt = node.right.take();

                if let Some(prev_rc) = prev_rc_opt {                    
                    prev_rc.borrow_mut().right = Some(node_rc.clone());
                }

                prev_rc_opt = Some(node_rc.clone());

                if let Some(right_rc) = right_rc_opt {
                    stack.push(right_rc);
                }

                if let Some(left_rc) = left_rc_opt {
                    stack.push(left_rc);
                }
            }
        }
    }
}
