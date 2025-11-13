impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let mut prev_byte_opt: Option<&u8> = None;
        let mut op_count = 0_i32;
        let mut curr_shift_cost = 0_i32;

        for byte in s.as_bytes().iter().rev() {
            if *byte == b'1' {
                op_count += curr_shift_cost;
            } else {
                match prev_byte_opt {
                    Some(prev_byte) => { 
                        if *prev_byte == b'1' {
                            curr_shift_cost += 1
                        }
                    },
                    None => curr_shift_cost += 1,
                }
            }

            prev_byte_opt = Some(byte);
        }

        op_count
    }
}
