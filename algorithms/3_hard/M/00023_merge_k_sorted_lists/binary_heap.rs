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
use std::collections::BinaryHeap;

impl Ord for ListNode {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.val.cmp(&other.val)
    }
}

impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {

        let mut heap: BinaryHeap<Box<ListNode>> = BinaryHeap::new();

        for mut curr_node_opt in lists.into_iter() {
            while let Some(mut curr_node) = curr_node_opt {
                curr_node_opt = curr_node.next.take();
                heap.push(curr_node);
            }
        }

        let mut head: Option<Box<ListNode>> = None;
        while let Some(mut curr_node) = heap.pop() {
            curr_node.next = head;
            head = Some(curr_node);
        }

        head
    }
}
