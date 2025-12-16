impl Solution {
    pub fn min_swaps(s: String) -> i32 {
        let mut curr_balance = 0_i32;
        let mut min_balance = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'[' {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance = min_balance.min(curr_balance);
        }

        (min_balance.abs() + 1) / 2
    }
}
