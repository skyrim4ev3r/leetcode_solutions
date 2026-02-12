impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut longest = 0_usize;

        for i in 0..len {
            let mut freqs = [0_i32; 26];

            for j in i..len {
                let freq_index = (bytes[j] - b'a') as usize;
                freqs[freq_index] += 1;
                let curr_freq = freqs[freq_index];

                if freqs.iter().all(|&freq| freq == 0 || freq == curr_freq) {
                    longest = longest.max(j - i + 1);
                }
            }
        }

        longest as i32
    }
}
