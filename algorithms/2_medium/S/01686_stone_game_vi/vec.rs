impl Solution {
    pub fn stone_game_vi(alice_values: Vec<i32>, bob_values: Vec<i32>) -> i32 {
        let n = alice_values.len();
        let mut vec: Vec<(i32, i32, i32)> = Vec::with_capacity(n);

        for i in 0..n {
            let priority = alice_values[i] + bob_values[i];
            vec.push((priority, alice_values[i], bob_values[i]));
        }

        vec.sort_unstable_by_key(|x| x.0);

        let mut alice_turn = true;
        let mut alice_score = 0_i32;
        let mut bob_score = 0_i32;

        for (_, alice_value, bob_value) in vec.into_iter().rev() {
            if alice_turn {
                alice_score += alice_value;
            } else {
                bob_score += bob_value;
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
