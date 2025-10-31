impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut max_depth = 0_i32;
        let mut curr_depth = 0_i32;

        for byte in s.into_bytes().into_iter() {
            if byte == b'(' {
                curr_depth += 1;
                max_depth = max_depth.max(curr_depth);
            } else if byte == b')' {
                curr_depth -= 1;
            }
        }

        max_depth
    }
}
