impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {

        let s_bytes = s.into_bytes();
        let len = s_bytes.len();
        let mut last_seen_index = [len; 128];
        let mut max_len = 0_usize;
        let mut left = 0_usize;

        for right in 0..len {

            let char_index = s_bytes[right] as usize;

            if last_seen_index[char_index] < len {
                left = left.max(last_seen_index[char_index] + 1);
            }

            last_seen_index[char_index] = right;

            max_len = max_len.max(right - left + 1);
        }

        max_len as i32
    }
}
