impl Solution {
    const MOD_TO: i32 = 1_000_000_007;
    pub fn count_homogenous(s: String) -> i32 {
        let mut prev_byte = b' ' ;
        let mut total_count = 0_i32;
        let mut contiguous_count = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == prev_byte {
                contiguous_count += 1;
            } else {
                contiguous_count = 1;
                prev_byte = *byte;
            }

            total_count = (total_count + contiguous_count) % Self::MOD_TO;
        }

        total_count
    }
}
