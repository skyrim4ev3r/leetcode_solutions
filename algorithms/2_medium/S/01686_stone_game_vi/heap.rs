use std::collections::BinaryHeap;

impl Solution {
    pub fn stone_game_vi(alice_values: Vec<i32>, bob_values: Vec<i32>) -> i32 {
        let n = alice_values.len();
        let mut heap: BinaryHeap<(i32, usize)> = BinaryHeap::with_capacity(n);

        for i in 0..n {
            let priority = alice_values[i] + bob_values[i];
            heap.push((priority, i));
        }

        let mut alice_turn = true;
        let mut alice_score = 0_i32;
        let mut bob_score = 0_i32;

        while let Some((_, i)) = heap.pop() {
            if alice_turn {
                alice_score += alice_values[i];
            } else {
                bob_score += bob_values[i];
            }

            alice_turn = !alice_turn;
        }

        match alice_score.cmp(&bob_score) {
            std::cmp::Ordering::Less => -1,
            std::cmp::Ordering::Equal => 0,
            std::cmp::Ordering::Greater => 1,
        }
    }
}
