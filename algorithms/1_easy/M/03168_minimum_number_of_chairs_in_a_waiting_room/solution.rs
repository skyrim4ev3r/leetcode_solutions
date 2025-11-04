impl Solution {
    pub fn minimum_chairs(s: String) -> i32 {

        let mut max = 0_i32;
        let mut balance = 0_i32;

        for byte in s.into_bytes() {
            if byte == b'E' {
                balance += 1;
                max = max.max(balance);
            } else {
                balance -= 1;
            }
        }

        max
    }
}
