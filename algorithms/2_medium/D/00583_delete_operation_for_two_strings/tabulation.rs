impl Solution {
    fn lcs<'a>(mut bytes1: &'a [u8], mut bytes2: &'a [u8]) -> i32 {
        if bytes1.is_empty() || bytes2.is_empty() {
            return 0;
        }

        if bytes1.len() < bytes2.len() {
            (bytes1, bytes2) = (bytes2, bytes1);
        }

        let (len1, len2) = (bytes1.len(), bytes2.len());
        let mut dp = vec![0_i32; 2 * (len2 + 1)];
        let (mut curr, mut next) = dp.split_at_mut(len2 + 1);

        for idx1 in (0..len1).rev() {
            for idx2 in (0..len2).rev() {
                if bytes1[idx1] == bytes2[idx2] {
                    curr[idx2] = 1 + next[idx2 + 1];
                } else {
                    curr[idx2] = curr[idx2 + 1].max(next[idx2]);
                }
            }

            (curr, next) = (next, curr);
        }

        next[0]
    }

    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (bytes1, bytes2) = (word1.as_bytes(), word2.as_bytes());

        (bytes1.len() + bytes2.len()) as i32 - 2 * Self::lcs(bytes1, bytes2)
    }
}
