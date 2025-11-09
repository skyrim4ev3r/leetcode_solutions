impl Solution {
    pub fn check_string(s: String) -> bool {
        for window in s.as_bytes().windows(2) {
            if window[1] < window[0] {
                return false;
            }
        }

        true
    }
}
