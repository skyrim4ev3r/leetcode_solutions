use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn helper(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, prev_rc_opt: &mut Option<Rc<RefCell<TreeNode>>>) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let left = curr_node_rc.borrow_mut().left.take();
            let right = curr_node_rc.borrow_mut().right.take();

            if let Some(prev_rc) = prev_rc_opt {
                let mut prev = prev_rc.borrow_mut();
                prev.right = Some(curr_node_rc.clone());
            }

            *prev_rc_opt = Some(curr_node_rc.clone());

            Self::helper(left.as_ref(), prev_rc_opt);
            Self::helper(right.as_ref(), prev_rc_opt);
        }
    }

    pub fn flatten(root_rc_opt: &mut Option<Rc<RefCell<TreeNode>>>) {
        let mut prev: Option<Rc<RefCell<TreeNode>>> = None;
        Self::helper(root_rc_opt.clone().as_ref(), &mut prev);
    }
}
