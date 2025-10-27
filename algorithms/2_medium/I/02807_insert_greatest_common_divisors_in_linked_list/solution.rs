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
    fn gcd(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a.abs()
    }

    pub fn insert_greatest_common_divisors(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if let Some(mut curr) = head.as_mut() {
            while let Some(next) = curr.next.take() {
                let mut new_node: Box<ListNode> = Box::new(ListNode::new(Self::gcd(curr.val, next.val)));
                new_node.next = Some(next);
                curr.next = Some(new_node);
                //curr = curr.next.as_mut().and_then(|n| n.next.as_mut()).unwrap();
                curr = curr.next.as_mut().unwrap().next.as_mut().unwrap();
            }
        }

        head
    }
}
