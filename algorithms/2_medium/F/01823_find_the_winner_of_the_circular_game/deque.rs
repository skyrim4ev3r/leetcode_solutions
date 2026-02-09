use std::collections::VecDeque;

impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        let mut q: VecDeque<i32> = (1..=n).into_iter().collect::<VecDeque<_>>();

        while q.len() > 1 {
            let curr_len = q.len() as i32;
            let index_to_del = if k % curr_len == 0 { curr_len - 1 } else { k % curr_len - 1 };
            q.rotate_left(index_to_del as usize);
            q.pop_front();
        }

        q.pop_front().unwrap()
    }
}
