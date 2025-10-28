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
    pub fn delete_middle(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        let mut count = 0_i32;
        let mut curr_opt =  head.as_ref();

        while let Some(curr) = curr_opt {
            count += 1;
            curr_opt = curr.next.as_ref();
        }

        if count <= 1 {
            return None;
        }

        let index_to_del = (count / 2) + 1;
        let mut curr_opt =  head.as_mut();
        let mut curr_index = 1_i32;

        while let Some(curr) = curr_opt {
            if curr_index == index_to_del - 1 {
                if let Some(mut next) = curr.next.take() {
                    curr.next = next.next;
                }
                break;
            }
            curr_index += 1;
            curr_opt = curr.next.as_mut();
        }

        head
    }
}
