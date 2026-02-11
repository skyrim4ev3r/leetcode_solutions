impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let len = s.len();
        let bytes = s.as_bytes();
        let mut freqs = [0_i32; 26];
        let mut left = 0_usize;
        let mut curr_max_freq = 0_i32;
        let mut res = 0_i32;

        for right in 0..len {
            let total = (right - left + 1) as i32;
            freqs[(bytes[right] - b'A') as usize] += 1;
            curr_max_freq = curr_max_freq.max(freqs[(bytes[right] - b'A') as usize]);

            if total - curr_max_freq > k {
                freqs[(bytes[left] - b'A') as usize] -= 1;
                left += 1;
            } else {
                res = total;
            }
        }

        res
    }
}
