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
    #[inline(always)]
    fn calc_len(mut curr_opt: Option<&Box<ListNode>>) -> i32 {
        let mut len = 0_i32;
        while let Some(curr) = curr_opt {
            curr_opt = curr.next.as_ref();
            len += 1;
        }
        len
    }

    pub fn split_list_to_parts(head: Option<Box<ListNode>>, k: i32) -> Vec<Option<Box<ListNode>>> {
        let len = Self::calc_len(head.as_ref());
        let seg_len = len / k;
        let mut extra = len % k;
        let mut curr = head;
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut res: Vec<Option<Box<ListNode>>> = vec![None; k as usize];

        for i in 0..(k as usize) {
            let mut prev = dummy.as_mut().unwrap();
            let target_len = seg_len + if extra > 0 { 1 } else { 0 };
            extra = extra.saturating_sub(1);

            if target_len == 0 {
                break;
            }

            for _ in 0..target_len {
                let next = curr.as_mut().unwrap().next.take();
                prev.next = curr;
                prev = prev.next.as_mut().unwrap();
                curr = next;
            }

            res[i] = dummy.as_mut().unwrap().next.take();
        }

        res
    }
}
