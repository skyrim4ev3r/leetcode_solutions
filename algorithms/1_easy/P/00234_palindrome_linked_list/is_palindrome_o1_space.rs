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
    pub fn is_palindrome(mut head: Option<Box<ListNode>>) -> bool {

        let mut count = 0;
        let mut curr = head.as_ref();

        while let Some(node) =  curr {
            count += 1;
            curr = node.next.as_ref();
        }

        if count == 1 {
            return true;
        }

        let mid = count / 2;
        let mut curr = head.as_mut();

        for _ in 1..mid {
            if let Some(node) =  curr {
                curr = node.next.as_mut();
            }
        }

        let mut next = curr.unwrap().next.take();
        if (count & 1) == 1 {
            next = next.unwrap().next;
        }

        let mut prev: Option<Box<ListNode>> = None;

        while let Some(mut node) = next {
            next = node.next.take();
            node.next = prev;
            prev = Some(node);
        }

        let mut head1 = head;
        let mut head2 = prev;

        // head1 and head2 have the same len
        while let Some(node1) = head1 && let Some(node2) = head2 {
            if node1.val != node2.val {
                return false;
            }

            head1 = node1.next;
            head2 = node2.next;
        }

        true
    }
}
