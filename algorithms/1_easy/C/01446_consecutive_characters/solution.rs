impl Solution {
    pub fn max_power(s: String) -> i32 {
        let mut curr_power = 1_i32;
        let mut max_power = 1_i32;
        let bytes = s.as_bytes();
        let len = bytes.len();

        for i in 1..len {
            if bytes[i] == bytes[i - 1] {
                curr_power += 1;
                max_power = max_power.max(curr_power);
            } else {
                curr_power = 1;
            }
        }

        max_power
    }
}
