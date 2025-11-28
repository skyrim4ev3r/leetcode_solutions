impl Solution {
    pub fn min_length_after_removals(s: String) -> i32 {
        let mut balance = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b'a' {
                balance += 1;
            } else {
                balance -= 1;
            }
        }

        balance.abs()
    }
}
