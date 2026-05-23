impl Solution {
    const MAP_LEN: usize = 256;

    pub fn length_of_longest_substring(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut last_seen: [Option<usize>; Solution::MAP_LEN] = [None; Solution::MAP_LEN];
        let mut max_len = 0_usize;
        let mut left = 0_usize;

        for right in 0..len {
            let idx = bytes[right] as usize;
            if let Some(prev_seen) = last_seen[idx] {
                left = left.max(prev_seen + 1);
            }
            max_len = max_len.max(right - left + 1);
            last_seen[idx] = Some(right);
        }

        max_len as i32

    }
}
