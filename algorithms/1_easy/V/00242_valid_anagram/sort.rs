impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut s_bytes = s.into_bytes();
        let mut t_bytes = t.into_bytes();

        s_bytes.sort_unstable();
        t_bytes.sort_unstable();

        s_bytes == t_bytes
    }
}
