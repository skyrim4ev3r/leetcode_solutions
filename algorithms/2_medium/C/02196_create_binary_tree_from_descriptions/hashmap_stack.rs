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
use std::collections::HashMap;

struct Data {
    left: i32,
    right: i32,
    can_be_root: bool,
}

impl Data {
    fn new(left: i32, right: i32, can_be_root: bool) -> Self {
        Self { left, right, can_be_root }
    }
}

impl Solution {
    #[inline(always)]
    fn create_hashmap(descriptions: Vec<Vec<i32>>) -> HashMap<i32, Data> {
        let mut hashmap: HashMap<i32, Data> = HashMap::with_capacity(descriptions.len() * 2);

        for d in descriptions {
            let (parent, child, right_left) = (d[0], d[1], d[2]);
            debug_assert!(parent > 0 && child > 0 && right_left >= 0 && right_left <= 1);
            hashmap.entry(parent).and_modify(|x| {
                if right_left == 0 {
                    debug_assert!(x.right == 0);
                    x.right = child;
                } else {
                    debug_assert!(x.left == 0);
                    x.left = child;
                }
            }).or_insert(Data::new(
                if right_left == 1 { child } else { 0 }, 
                if right_left == 0 { child } else { 0 },
                true,
            ));

            hashmap.entry(child).and_modify(|x| x.can_be_root = false).or_insert(Data::new(0, 0, false));
        }

        hashmap
    }

    #[inline(always)]
    fn find_root(hashmap: &HashMap<i32, Data>) -> i32 {
        for (p, data) in hashmap {
            if data.can_be_root {
                return *p;
            }
        }

        unreachable!()
    }

    pub fn create_binary_tree(descriptions: Vec<Vec<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        debug_assert!(descriptions.len() > 0);
        let hashmap = Self::create_hashmap(descriptions);
        let root_val = Self::find_root(&hashmap);

        let mut stack: Vec<Rc<RefCell<TreeNode>>> = Vec::with_capacity(hashmap.len());
        let root_rc = Rc::new(RefCell::new(TreeNode::new(root_val)));
        stack.push(root_rc.clone());

        while let Some(parent_rc) = stack.pop() {
            let data = &hashmap[&parent_rc.borrow().val];

            if data.left > 0 {
                let node_rc= Rc::new(RefCell::new(TreeNode::new(data.left)));
                parent_rc.borrow_mut().left = Some(node_rc.clone());
                stack.push(node_rc)
            }

            if data.right > 0 {
                let node_rc= Rc::new(RefCell::new(TreeNode::new(data.right)));
                parent_rc.borrow_mut().right = Some(node_rc.clone());
                stack.push(node_rc)
            }
        }

        Some(root_rc)
    }
}
