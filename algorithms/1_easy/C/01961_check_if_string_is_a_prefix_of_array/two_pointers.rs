impl Solution {
    pub fn is_prefix_string(s: String, words: Vec<String>) -> bool {

        let s_bytes = s.into_bytes();
        let s_bytes_len = s_bytes.len();
        let mut s_index = 0_usize;

        for word in words.into_iter() {

            let word_bytes = word.into_bytes();
            let word_bytes_len = word_bytes.len();
            let mut w_index = 0_usize;

            if word_bytes_len > s_bytes_len - s_index {
                return false;
            }

            while w_index < word_bytes_len && word_bytes[w_index] == s_bytes[s_index] {
                s_index += 1;
                w_index += 1;
            }

            if w_index != word_bytes_len {
                return false;
            }

            if s_index == s_bytes_len {
                return true;
            }
        }

        false
    }
}
