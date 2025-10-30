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
use std::collections::BTreeMap;

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut nums_map: BTreeMap<i32, i32> = BTreeMap::new();
        for mut curr_node_opt in lists.into_iter() {
            while let Some(curr_node) = curr_node_opt {
                *nums_map.entry(curr_node.val).or_insert(0) += 1;
                curr_node_opt = curr_node.next;
            }
        }

        let mut head: Option<Box<ListNode>> = None;
        for it in  nums_map.into_iter().rev() {
            let num = it.0;
            for i in 0..it.1 {
                let mut new_node = Box::new(ListNode::new(num));
                new_node.next = head;
                head = Some(new_node);
            }
        }

        head
    }
}
