// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
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

    #[inline(always)]
    fn calc_len(mut curr_opt: Option<&Box<ListNode>>) -> usize {
        let mut len = 0_usize;

        while let Some(curr) = curr_opt {
            len += 1;
            curr_opt = curr.next.as_ref();
        }

        len
    }

    fn divide_list_and_make_tree(
        curr: Option<&Box<ListNode>>,
        len: usize
    ) -> (
        Option<Rc<RefCell<TreeNode>>>,
        Option<&Box<ListNode>>,
    ) {
        if len == 0 {
            return (None, curr);
        }

        let mid_index = len / 2;
        let left_len = mid_index;
        let right_len = len - 1 - mid_index;

        let (left_tree, mid_node) = Self::divide_list_and_make_tree(curr, left_len);
        let (right_tree, next_node) = Self::divide_list_and_make_tree(
            mid_node.clone().unwrap().next.as_ref(),
            right_len,
        );

        let new_node_rc = Rc::new(RefCell::new(TreeNode::new(mid_node.unwrap().val)));

        {
            let mut new_node = new_node_rc.borrow_mut();
            new_node.left = left_tree;
            new_node.right = right_tree;
        }

        (Some(new_node_rc), next_node)
    }

    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let len = Self::calc_len(head.as_ref());

        Self::divide_list_and_make_tree(head.as_ref(), len).0
    }
}
