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
    pub fn merge_two_lists(mut list1: Option<Box<ListNode>>, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        let mut dummy = Box::new(ListNode::new(0));
        let mut prev = dummy.as_mut();

        while let Some(ref node1) = list1 && let Some(ref node2) = list2 {
            if node1.val < node2.val {
                prev.next = list1;
                prev = prev.next.as_mut().unwrap();
                list1 = prev.next.take();
            } else {
                prev.next = list2;
                prev = prev.next.as_mut().unwrap();
                list2 = prev.next.take();
            }
        }

        prev.next = list1.or(list2);

        dummy.next
    }
}
