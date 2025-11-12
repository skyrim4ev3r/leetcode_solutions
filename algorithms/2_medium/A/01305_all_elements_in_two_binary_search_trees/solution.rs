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
    fn travers(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, vec: &mut Vec<i32>) {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();

            Self::travers(node.left.as_ref(), vec);
            vec.push(node.val);
            Self::travers(node.right.as_ref(), vec);
        }
    }
    pub fn get_all_elements(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut vec1: Vec<i32> = Vec::new();
        let mut vec2: Vec<i32> = Vec::new();

        Self::travers(root1.as_ref(), &mut vec1);
        Self::travers(root2.as_ref(), &mut vec2);

        let vec1_len = vec1.len();
        let vec2_len = vec2.len();

        let mut res: Vec<i32> = Vec::with_capacity(vec1_len + vec2_len);

        let mut i1 = 0_usize;
        let mut i2 = 0_usize;

        while i1 < vec1_len && i2 < vec2_len {
            if vec1[i1] <= vec2[i2] {
                res.push(vec1[i1]);
                i1 += 1;
            } else {
                res.push(vec2[i2]);
                i2 += 1;
            }
        }

        while i1 < vec1_len {
            res.push(vec1[i1]);
            i1 += 1;
        }

        while i2 < vec2_len {
            res.push(vec2[i2]);
            i2 += 1;
        }

        res
    }
}
