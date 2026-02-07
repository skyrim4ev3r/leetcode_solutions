impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut res = 0_i32;
        let mut b_count = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'b' {
                b_count += 1;
            } else if b_count > 0 {
                res += 1;
                b_count -= 1;
            }
        }

        res
    }
}
