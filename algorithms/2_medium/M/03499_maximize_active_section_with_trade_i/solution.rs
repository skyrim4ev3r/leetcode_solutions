impl Solution {
    pub fn max_active_sections_after_trade(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut total_ones = 0_i32;
        let mut prev_zeros = 0_i32;
        let mut curr_zeros = 0_i32;
        let mut max = 0_i32;

        for i in 0..len {
            match bytes[i] {
                b'0' => {
                    curr_zeros += 1;
                    if prev_zeros > 0 {
                        max = max.max(prev_zeros + curr_zeros);
                    }
                },
                b'1' => {
                    if i > 0 && bytes[i - 1] == b'0' {
                        prev_zeros = curr_zeros;
                        curr_zeros = 0;
                    }
                    total_ones += 1;
                },
                _ => panic!("invalid input"),
            }
        }

        max + total_ones
    }
}
