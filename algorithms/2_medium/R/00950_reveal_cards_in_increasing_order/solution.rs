use std::collections::VecDeque;

impl Solution {
    pub fn deck_revealed_increasing(mut deck: Vec<i32>) -> Vec<i32> {
        let mut q = VecDeque::with_capacity(deck.len());
        deck.sort_unstable_by(|a, b| b.cmp(&a));

        for d in deck.into_iter() {
            if let Some(val) = q.pop_back() {
                q.push_front(val);
            }

            q.push_front(d);
        }

        q.into_iter().collect::<Vec<_>>()
    }
}
