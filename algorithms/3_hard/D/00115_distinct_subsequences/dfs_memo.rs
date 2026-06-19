impl Solution {
    fn dfs(b1: &[u8], idx1: usize, b2: &[u8], idx2: usize, memo: &mut[i32]) -> i32 {
        let (len1, len2) = (b1.len(), b2.len());
        if idx2 == len2 { return 1; }
        if idx1 == len1 { return 0; }

        let (remain1, remain2) = (len1 - idx1, len2 - idx2);
        if remain1 < remain2 { return 0; }

        let memo_idx = idx1 * len2 + idx2;
        if memo[memo_idx] != -1 { return memo[memo_idx]; }

        let mut res = 0_i32;
        if b1[idx1] == b2[idx2] {
            res += Self::dfs(b1, idx1 + 1, b2, idx2 + 1, memo);
        }

        res += Self::dfs(b1, idx1 + 1, b2, idx2, memo);
        memo[memo_idx] = res;
        res
    }

    pub fn num_distinct(s: String, t: String) -> i32 {
        if s.len() < t.len() {
            return 0;
        }

        let mut memo = vec![-1_i32; s.len() * t.len()];

        Self::dfs(s.as_bytes(), 0, t.as_bytes(), 0, &mut memo)
    }
}
