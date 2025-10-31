impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        let len = s.len();

        if len < 2 {
            return false;
        }

        let s_bytes = s.into_bytes();
        let s_bytes_slice = &s_bytes;

        let mut s_bytes_doubled: Vec<u8> = Vec::with_capacity(2 * len);
        s_bytes_doubled.extend_from_slice(s_bytes_slice);
        s_bytes_doubled.extend_from_slice(s_bytes_slice);

        return s_bytes_doubled[1..=(2 * len - 2)].windows(len).any(|x| x == s_bytes_slice); 
    }
}
