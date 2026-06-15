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
    pub fn delete_middle(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        assert!(head.is_some());
        let mut dummy = ListNode::new(0);
        dummy.next = head;

        unsafe {
            let mut fast = &raw mut dummy;
            let mut slow = &raw mut dummy;

            while (*fast).next.is_some() && (*fast).next.as_ref().unwrap().next.is_some()  {
                fast = (*fast).next.as_mut().unwrap().next.as_mut().unwrap().as_mut() as *mut ListNode;
                slow = (*slow).next.as_mut().unwrap().as_mut() as *mut ListNode;
            }

            (*slow).next = (*slow).next.take().unwrap().next;
        }

        dummy.next
    }
}
