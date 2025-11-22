impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut first_seen_s = [-1_isize; 128];
        let mut first_seen_t = [-1_isize; 128];
        let s_bytes = s.as_bytes();
        let t_bytes = t.as_bytes();
        let len = s_bytes.len();

        for i in 0..len {
            let ch_s_as_index = s_bytes[i] as usize;
            let ch_t_as_index = t_bytes[i] as usize;

            if first_seen_s[ch_s_as_index] == -1 {
                first_seen_s[ch_s_as_index] = i as isize;
            }

            if first_seen_t[ch_t_as_index] == -1 {
                first_seen_t[ch_t_as_index] = i as isize;
            }

            if first_seen_s[ch_s_as_index] != first_seen_t[ch_t_as_index] {
                return false;
            }
        }

        true
    }
}
