impl Solution {
    pub fn best_closing_time(customers: String) -> i32 {
        let len = customers.len();
        let bytes = customers.as_bytes();
        let mut curr_y  = bytes.iter().filter(|x| **x == b'Y').count() as i32;
        let mut curr_n  = 0_i32;
        let mut min_penalty  = curr_y;
        let mut min_penalty_index = 0_usize;

        for i in 1..=len {
            if bytes[i - 1] == b'N' {
                curr_n += 1;
            } else {
                curr_y -= 1;
            }

            let total = curr_y + curr_n;

            if total < min_penalty {
                min_penalty = total;
                min_penalty_index = i;
            }
        }

        min_penalty_index as i32
    }
}
