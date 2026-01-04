impl Solution {
    pub fn maximum_length_substring(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut window_freqs = [0_i32; 26];
        let mut left = 0_usize;
        let mut max = 0_usize;

        for right in 0..len {
            let index = (bytes[right] - b'a') as usize;
            window_freqs[index] += 1;

            while window_freqs[index] > 2 {
                window_freqs[(bytes[left] - b'a') as usize] -= 1;
                left += 1;
            }

            max = max.max(right + 1 - left);
        }

        max as i32
    }
}
