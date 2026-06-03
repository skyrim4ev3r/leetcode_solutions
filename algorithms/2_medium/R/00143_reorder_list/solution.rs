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
    fn reverse(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut curr_opt = head;
        let mut new_head: Option<Box<ListNode>> = None;

        while let Some(mut curr) = curr_opt {
            curr_opt = curr.next.take();
            curr.next = new_head;
            new_head = Some(curr);
        }

        new_head
    }

    #[inline(always)]
    fn calc_len(head: &Option<Box<ListNode>>) -> usize {
        let mut len = 0_usize;
        let mut curr_opt = head;
        while let Some(curr) = curr_opt {
            len += 1;
            curr_opt = &curr.next;
        }
        len
    }

    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        let len = Self::calc_len(head);

        if len <= 2 {
            return;
        }

        let mut curr = head.as_mut().unwrap();
        let mid = (len + 1) / 2;

        for _ in 1..mid {
            curr = curr.next.as_mut().unwrap();
        }

        let mut h2_opt = Self::reverse(curr.next.take());
        let mut h1_opt = head.as_mut().unwrap().next.take();
        let mut prev: &mut ListNode = head.as_mut().unwrap().as_mut();

        while h1_opt.is_some() && h2_opt.is_some() {
            let mut h1 = h1_opt.unwrap();
            let mut h2 = h2_opt.unwrap();

            h2_opt = h2.next.take();
            prev.next = Some(h2);
            prev = prev.next.as_mut().unwrap();

            h1_opt = h1.next.take();
            prev.next = Some(h1);
            prev = prev.next.as_mut().unwrap();
        }

        prev.next = h2_opt;
    }
}
