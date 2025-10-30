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
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut prev = &mut dummy;

        let mut curr_node_opt = head;

        while let Some(mut curr_node) = curr_node_opt {
            if let Some(mut next_node) = curr_node.next.take() {
                curr_node.next = next_node.next.take();
                next_node.next = Some(curr_node);
                prev.next = Some(next_node);
                prev = &mut (*(prev.next.as_mut().unwrap().next.as_mut().unwrap()));
                curr_node_opt = prev.next.take();
            } else {
                prev.next = Some(curr_node);
                break;
            }
        }

        return dummy.next;
    }
}
