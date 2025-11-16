impl Solution {
    const mod_to: i32 = 1_000_000_007;

    pub fn num_sub(s: String) -> i32 {
        let mut total_count = 0_i32;
        let mut curr_count = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'1' {
                curr_count += 1;
            } else {
                curr_count = 0;
            }

            total_count = (total_count + curr_count) % Self::mod_to;
        }

        total_count
    }
}
