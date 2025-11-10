impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {

        let mut count = 0;
        let mut curr_diff = 0;

        for byte in s.into_bytes().into_iter() {
            if byte == b'R' {
                curr_diff += 1;
            } else {
                curr_diff -= 1;
            }

            if curr_diff == 0 {
                count += 1;
            }
        }

        count
    }
}
