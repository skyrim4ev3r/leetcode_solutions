impl Solution {
    pub fn minimum_steps(s: String) -> i64 {
        let mut zeros_count = 0_usize;
        let mut cost = 0_i64;

        for (i, byte) in s.as_bytes().iter().enumerate() {
            if *byte == b'0' {
                cost += (i - zeros_count) as i64;
                zeros_count += 1;
            }
        }

        cost
    }
}
