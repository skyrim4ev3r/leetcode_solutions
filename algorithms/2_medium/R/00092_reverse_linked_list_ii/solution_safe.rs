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
    pub fn reverse_between(head: Option<Box<ListNode>>, left: i32, right: i32) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        dummy.next = head;
        let mut tail_part_one = &mut dummy;

        for _ in 1..left {
            tail_part_one = tail_part_one.next.as_mut().unwrap().as_mut();
        }

        let mut curr = tail_part_one.next.take();
        let mut head_part_two: Option<Box<ListNode>> = None;

        for _ in left..=right {
            let mut next = curr.as_mut().unwrap().next.take();
            curr.as_mut().unwrap().next = head_part_two;
            head_part_two = curr;
            curr = next;
        }

        tail_part_one.next = head_part_two;
        let mut tail_part_two = tail_part_one;

        while tail_part_two.next.is_some() {
            tail_part_two = tail_part_two.next.as_mut().unwrap().as_mut();
        }

        tail_part_two.next = curr;

        dummy.next
    }
}
