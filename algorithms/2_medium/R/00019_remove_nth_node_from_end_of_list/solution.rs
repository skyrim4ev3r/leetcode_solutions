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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {

        let mut right = head.as_ref();
        let mut count = 0_i32;

        while let Some(node) = right {
            count += 1;
            right = node.next.as_ref();
        }

        let mut dummy: Box<ListNode> = Box::new(ListNode::new(0));
        dummy.next = head;
        let mut prev = dummy.as_mut();

        for i in 0..(count - n) {
            prev = prev.next.as_mut().unwrap();
        }

        let next = prev.next.take();
        prev.next = next.unwrap().next;

        dummy.next
    }
}
