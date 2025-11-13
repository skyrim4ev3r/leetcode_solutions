impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let len = s.len();
        let s_bytes = s.as_bytes();
        let mut op_count = 0_i32;
        let mut curr_shift_cost = 0_i32;

        for i in (0..len).rev() {
            if s_bytes[i] == b'1' {
                op_count += curr_shift_cost;
            } else if i + 1 == len || s_bytes[i + 1] == b'1' {
                curr_shift_cost += 1;
            }
        }

        op_count
    }
}
