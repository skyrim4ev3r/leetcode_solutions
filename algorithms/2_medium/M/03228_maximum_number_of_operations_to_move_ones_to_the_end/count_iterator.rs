impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let mut prev_byte_opt: Option<&u8> = None;
        let mut op_count = 0_i32;
        let mut count_ones = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'1' {
                count_ones += 1;
            } else if let Some(prev_byte) = prev_byte_opt && *prev_byte == b'1' {
                op_count += count_ones;
            }

            prev_byte_opt = Some(byte);
        }

        op_count
    }
}
