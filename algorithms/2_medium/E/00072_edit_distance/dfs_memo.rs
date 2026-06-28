impl Solution {
    fn dfs(w1: &[u8], i1: usize, w2: &[u8], i2: usize, memo: &mut[i32]) -> i32 {
        let (len1, len2) = (w1.len(), w2.len());
        if i1 == len1 {
            return (len2 - i2) as i32;
        }

        if i2 == len2 {
            return (len1 - i1) as i32;
        }

        let memo_idx = i1 * len2 + i2;

        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut res = if w1[i1] == w2[i2] {
            Self::dfs(w1, i1 + 1, w2, i2 + 1, memo)
        } else {
            (1 + Self::dfs(w1, i1 + 1, w2, i2 + 1, memo))
            .min(1 + Self::dfs(w1, i1, w2, i2 + 1, memo))
            .min(1 + Self::dfs(w1, i1 + 1, w2, i2, memo))
        };

        memo[memo_idx] = res;
        res
    }

    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (w1, w2) = (word1.as_bytes(), word2.as_bytes());
        let mut memo = vec![-1; w1.len() * w2.len()];

        Self::dfs(w1, 0, w2, 0, &mut memo)
    }
}
