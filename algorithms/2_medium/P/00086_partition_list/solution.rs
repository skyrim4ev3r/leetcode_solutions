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
    pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut dummy1 = ListNode::new(0);
        let mut dummy2 = ListNode::new(0);
        let mut prev1 = &mut dummy1;
        let mut prev2 = &mut dummy2;
        let mut curr_opt = head;

        while let Some(mut curr) = curr_opt {
            let next = curr.next.take();

            if curr.val < x {
                prev1.next = Some(curr);
                prev1 = prev1.next.as_mut().unwrap().as_mut();
            } else {
                prev2.next = Some(curr);
                prev2 = prev2.next.as_mut().unwrap().as_mut();
            }

            curr_opt = next;
        }

        prev1.next = dummy2.next;

        dummy1.next
    }
}
