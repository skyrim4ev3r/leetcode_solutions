use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, res: &mut Vec<u8>) {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();

            res.extend_from_slice(curr_node.val.to_string().as_bytes());

            if curr_node.left.is_some() || curr_node.right.is_some() {
                res.push(b'(');
                Self::dfs(curr_node.left.as_ref(), res);
                res.push(b')');

                if curr_node.right.is_some() {
                    res.push(b'(');
                    Self::dfs(curr_node.right.as_ref(), res);
                    res.push(b')');
                }
            }
        }
    }

    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res: Vec<u8> = Vec::new();
        Self::dfs(root.as_ref(), &mut res);

        String::from_utf8(res).unwrap()
    }
}
