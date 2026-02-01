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
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        let mut curr_opt = head;

        while let Some(mut curr) = curr_opt {
            curr_opt = curr.next.take();
            res.push(curr.val);
        }

        let len = res.len();
        let mut stack: Vec<i32> = Vec::new();

        for i in (0..len).rev() {
            let curr_val = res[i];

            while let Some(top_val) = stack.last() && *top_val <= curr_val {
                stack.pop();
            }

            if stack.is_empty() {
                res[i] = 0;
            } else {
                res[i] = *stack.last().unwrap();
            }

            stack.push(curr_val);
        }

        res
    }
}
