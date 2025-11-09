use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn check_tree(root_rc_opt: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let root = root_rc_opt.as_ref().unwrap().borrow();
        let left = root.left.as_ref().unwrap().borrow();
        let right = root.right.as_ref().unwrap().borrow();

        root.val == left.val + right.val
    }
}
