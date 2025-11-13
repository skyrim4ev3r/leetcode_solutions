impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let s_bytes = s.as_bytes();
        let len = s_bytes.len();
        let mut count = 0_i32;

        for i in 0..(len - 1) {
            let mut left = i;
            let mut right = i + 1;

            if s_bytes[left] != s_bytes[right] {
                while left < len && right < len {
                    count += 1;

                    if left > 0 && s_bytes[left - 1] == s_bytes[left] && right < len - 1 && s_bytes[right] == s_bytes[right + 1] {
                        left -= 1;
                        right += 1;
                    } else {
                        break;
                    }
                }
            }
        }

        count
    }
}
