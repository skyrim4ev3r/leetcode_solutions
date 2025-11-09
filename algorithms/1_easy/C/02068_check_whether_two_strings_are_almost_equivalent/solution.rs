impl Solution {
    pub fn check_almost_equivalent(word1: String, word2: String) -> bool {
        let mut freqs = [0_i32; 26];

        for byte in word1.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        for byte in word2.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] -= 1;
        }

        for freq in freqs.into_iter() {
            if freq.abs() > 3 {
                return false;
            }
        }

        true
    }
}
