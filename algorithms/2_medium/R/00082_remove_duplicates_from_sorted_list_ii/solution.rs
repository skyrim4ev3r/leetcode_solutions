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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut prev = &mut dummy;
        let mut curr_opt = head;

        while curr_opt.as_ref().is_some_and(|c| c.next.as_ref().is_some()) {
            let curr = curr_opt.as_ref().unwrap();
            let curr_val = curr.val;
            let next_val = curr.next.as_ref().unwrap().val;

            if curr_val == next_val {
                while curr_opt.as_ref().is_some_and(|c| c.val == curr_val)  {
                    curr_opt = curr_opt.unwrap().next.take();
                }
            } else {
                prev.next = curr_opt;
                prev = prev.next.as_mut().unwrap();
                curr_opt = prev.next.take();
            }
        }

        prev.next = curr_opt;

        dummy.next.take()
    }
}
