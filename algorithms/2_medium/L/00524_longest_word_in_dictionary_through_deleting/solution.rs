impl Solution {
    fn is_sub(s: &[u8], t: &[u8]) -> bool {
        let (s_len, t_len) = (s.len(), t.len());

        if s_len < t_len { return false; }

        if t_len == 0 { return true; }

        let mut t_idx = 0_usize;

        for (s_idx, &s_byte) in s.into_iter().enumerate() {
            if s_byte == t[t_idx] {
                t_idx += 1;

                if t_idx == t_len {
                    return true;
                }
            }

            if s_len - s_idx < t_len - t_idx {
                return false;
            }
        }

        false
    }

    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let s_bytes = s.as_bytes();
        let mut selected_bytes: Vec<u8> = Vec::new();

        for d in dictionary {
            let d_bytes = d.into_bytes();
            if Self::is_sub(s_bytes, &d_bytes) {
                if selected_bytes.len() < d_bytes.len() {
                    selected_bytes = d_bytes;
                } else if selected_bytes.len() == d_bytes.len() &&  selected_bytes > d_bytes {
                    selected_bytes = d_bytes;
                }
            }
        }

        String::from_utf8(selected_bytes).unwrap()
    }
}
