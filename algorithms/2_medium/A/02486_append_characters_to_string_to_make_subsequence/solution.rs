impl Solution {
    pub fn append_characters(s: String, t: String) -> i32 {
        let s = s.into_bytes();
        let t = t.into_bytes();

        let s_len = s.len();
        let t_len = t.len();

        let mut s_index = 0_usize;
        let mut t_index = 0_usize;

        while s_index < s_len && t_index < t_len {
            if s[s_index] == t[t_index] {
                t_index += 1;
            }
            s_index += 1;
        } 

        (t_len - t_index) as i32
    }
}
