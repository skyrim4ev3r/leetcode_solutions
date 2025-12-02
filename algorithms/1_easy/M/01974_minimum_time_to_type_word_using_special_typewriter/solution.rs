impl Solution {
    pub fn min_time_to_type(word: String) -> i32 {
        let mut circle_pos = 0_i32;
        let mut cost = 0_i32;

        for byte in word.as_bytes().iter() {
            let new_pos = (*byte - b'a') as i32;
            let curr_diff = (new_pos - circle_pos).abs();

            let min_cost = curr_diff.min(26 - curr_diff);

            cost += min_cost + 1;
            circle_pos = new_pos;
        }

        cost
    }
}
