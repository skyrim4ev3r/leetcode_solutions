impl Solution {
    fn dfs(
        b1: &[u8],
        b1_idx: usize,
        b2: &[u8],
        b2_idx: usize,
        b3: &[u8],
        b3_idx: usize,
        memo: &mut [bool],
    ) -> bool {
        let (b1_len, b2_len, b3_len) = (b1.len(), b2.len(), b3.len());

        if b3_idx == b3_len {
            return true;
        }

        let memo_idx = b1_idx * (b2_len + 1) + b2_idx;

        if !memo[memo_idx] {
            return false;
        }

        if b1_idx < b1_len && b1[b1_idx] == b3[b3_idx] {
            if Self::dfs(b1, b1_idx + 1, b2, b2_idx, b3, b3_idx + 1, memo) {
                return true;
            }
        }

        if b2_idx < b2_len && b2[b2_idx] == b3[b3_idx] {
            if Self::dfs(b1, b1_idx, b2, b2_idx + 1, b3, b3_idx + 1, memo) {
                return true;
            }
        }

        memo[memo_idx] = false;
        false
    }

    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let (b1, b2, b3) = (s1.as_bytes(), s2.as_bytes(), s3.as_bytes());
        let (b1_len, b2_len, b3_len) = (b1.len(), b2.len(), b3.len());

        if b1_len + b2_len != b3_len {
            return false;
        }

        if b1_len == 0 || b2_len == 0 {
            return b3 == b1 || b3 == b2;
        }

        let mut memo = vec![true; (b1_len + 1) * (b2_len + 1)];

        Self::dfs(b1, 0, b2, 0, b3, 0, &mut memo)
    }
}
