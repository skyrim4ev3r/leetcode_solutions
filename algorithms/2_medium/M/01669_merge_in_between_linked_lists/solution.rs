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
    pub fn merge_in_between(mut list1: Option<Box<ListNode>>, a: i32, b: i32, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode::new(0)));
        dummy.as_mut().unwrap().next = list1;

        let mut prev_a = &mut dummy;
        for _ in 0..a {
            prev_a = &mut prev_a.as_mut().unwrap().next; 
        }

        let mut node_b = &mut prev_a.as_mut().unwrap().next.take(); 
        for _ in a..b {
            node_b = &mut node_b.as_mut().unwrap().next; 
        }

        let mut last_node_list2 = &mut list2;
        while last_node_list2.as_ref().unwrap().next.is_some() {
            last_node_list2 = &mut last_node_list2.as_mut().unwrap().next;
        }

        last_node_list2.as_mut().unwrap().next = node_b.as_mut().unwrap().next.take();
        prev_a.as_mut().unwrap().next = list2;

        dummy.unwrap().next
    }
}
