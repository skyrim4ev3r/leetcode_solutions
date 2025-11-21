impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut is_seen = [false; 26];
        let mut masks = [0_u32; 26];
        let mut scores = [0_u32; 26];

        for i in 0..len {
            let chr_index = (bytes[i] - b'a') as usize;
            let mask = 1_u32 << chr_index;

            if is_seen[chr_index] {
                scores[chr_index] = masks[chr_index].count_ones();
            }

            for j in 0..26 {
                if is_seen[j] {
                    masks[j] |= mask;
                }
            }

            is_seen[chr_index] = true;
        }

        scores.into_iter().sum::<u32>() as i32
    }
}
