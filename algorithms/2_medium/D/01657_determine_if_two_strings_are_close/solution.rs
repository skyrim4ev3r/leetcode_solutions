impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        if word1.len() != word2.len() {
            return false;
        }

        let mut freq1 = [0_i32; 26];
        let mut freq2 = [0_i32; 26];

        word1.into_bytes().into_iter().for_each(|byte| freq1[(byte - b'a') as usize] += 1);
        word2.into_bytes().into_iter().for_each(|byte| freq2[(byte - b'a') as usize] += 1);

        for i in 0..26 {
            if (freq1[i] > 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0) {
                return false;
            }
        }

        freq1.sort_unstable();
        freq2.sort_unstable();

        freq1 == freq2
    }
}
