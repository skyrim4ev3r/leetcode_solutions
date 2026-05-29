impl Solution {
    fn dfs(
        b1: &[u8],
        b1_idx: usize,
        b1_len: usize,
        b2: &[u8],
        b2_idx: usize,
        b2_len: usize,
        memo: &mut [i32],
    ) -> i32 {
        if b1_idx == b1_len || b2_idx == b2_len {
            return 0;
        }

        let memo_idx = (b1_idx * b2_len) + b2_idx;
        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut max = 0_i32;

        if b1[b1_idx] == b2[b2_idx] {
            max = 1 + Self::dfs(b1, b1_idx + 1, b1_len, b2, b2_idx + 1, b2_len, memo);
        } else {
            let skip1 = Self::dfs(b1, b1_idx + 1, b1_len, b2, b2_idx, b2_len, memo);
            let skip2 = Self::dfs(b1, b1_idx, b1_len, b2, b2_idx + 1, b2_len, memo);
            max = skip1.max(skip2);
        }

        memo[memo_idx] = max;

        max
    }

    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let b1 = text1.as_bytes();
        let b2 = text2.as_bytes();
        let b1_len = b1.len();
        let b2_len = b2.len();
        let b1_start_idx = 0_usize;
        let b2_start_idx = 0_usize;
        let mut memo = vec![-1_i32; b1_len * b2_len];

        Self::dfs(b1, b1_start_idx, b1_len, b2, b2_start_idx, b2_len, &mut memo)
    }
}
