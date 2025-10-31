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
    pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        if head.is_none() {
            return None;
        }

        let mut curr = head.as_mut().unwrap();
        let mut next_opt = curr.next.take();

        while let Some(mut next) = next_opt {
            if curr.val == next.val {
                next_opt = next.next.take();
            } else {
                curr.next = Some(next);
                curr = curr.next.as_mut().unwrap();
                next_opt = curr.next.take();
            }
        } 

        head
    }
}
