use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn flatten(root_rc_opt: &mut Option<Rc<RefCell<TreeNode>>>) {
        let mut curr_rc_opt = root_rc_opt.clone();

        while let Some(curr_rc) = curr_rc_opt {
            let mut curr = curr_rc.borrow_mut();

            if curr.left.is_none() {
                curr_rc_opt = curr.right.clone();
            } else {
                let left = curr.left.take();

                if curr.right.is_none() { 
                    curr_rc_opt = left.clone();
                    curr.right = left;
                } else {
                    let right = curr.right.take();
                    
                    let mut temp_rc_opt = left.clone();

                    while let Some(temp_rc) = temp_rc_opt {
                        let mut temp = temp_rc.borrow_mut();
                        if temp.right.is_none() {
                            temp.right = right;
                            break;
                        } else {
                            temp_rc_opt = temp.right.clone();
                        }
                    }

                    curr_rc_opt = left.clone();
                    curr.right = left;
                }
            }
        }
    }
}
