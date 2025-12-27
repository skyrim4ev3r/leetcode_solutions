impl Solution {
    pub fn best_closing_time(customers: String) -> i32 {
        let len = customers.len();
        let bytes = customers.as_bytes();
        let mut curr_penalty = 0_i32;
        let mut min_penalty  = 0_i32;
        let mut min_penalty_index = 0_usize;

        for i in 1..=len {
            if bytes[i - 1] == b'N' {
                curr_penalty += 1;
            } else {
                curr_penalty -= 1;
            }

            if curr_penalty < min_penalty {
                min_penalty = curr_penalty;
                min_penalty_index = i;
            }
        }

        min_penalty_index as i32
    }
}
