impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let s_bytes = s.into_bytes();
        let t_bytes = t.into_bytes();

        let s_len = s_bytes.len();
        let t_len = t_bytes.len();

        let mut s_index = 0_usize;
        let mut t_index = 0_usize;

        loop {
            if s_index == s_len {
                return true;
            }

            if t_index == t_len {
                return false;
            }

            if s_bytes[s_index] == t_bytes[t_index] {
                s_index += 1;
            }

            t_index += 1;
        }
    }
}
