impl Solution {
    const MAP_LEN: usize = 256;

    pub fn length_of_longest_substring(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len() as isize;
        let mut last_seen = [-1_isize; Self::MAP_LEN];
        let mut longest_substr = 0_isize;
        let mut lo = 0_isize;

        for hi in 0..len {
            let idx_last_seen = bytes[hi as usize] as usize;
            lo = lo.max(last_seen[idx_last_seen] + 1);
            longest_substr = longest_substr.max(hi - lo + 1);
            last_seen[idx_last_seen] = hi;
        }

        longest_substr as i32
    }
}
