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
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut prev = &mut dummy;
        let mut curr = head;

        while let Some(mut node) = curr {
            if node.val != val {
                let next = node.next.take();
                prev.next = Some(node);
                prev = prev.next.as_mut().unwrap();
                curr = next;
            } else {
                curr = node.next.take();
            }
        }

        dummy.next
    }
}
