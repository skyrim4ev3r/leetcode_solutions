impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut curr_balance = 0_i32;
        let mut min_balance_left = 0_i32;
        let mut min_balance_right = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'(' {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance_left = min_balance_left.min(curr_balance);
        }

        curr_balance = 0;
        for byte in s.as_bytes().iter().rev() {
            if *byte == b')' {
                curr_balance += 1;
            } else {
                curr_balance -= 1;
            }

            min_balance_right = min_balance_right.min(curr_balance);
        }

        min_balance_left.abs() + min_balance_right.abs()
    }
}
