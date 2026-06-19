impl Solution {
    fn dfs(bytes1: &[u8], idx1: usize, bytes2: &[u8], idx2: usize, memo: &mut [i32]) -> i32 {
        let (len1, len2) = (bytes1.len(), bytes2.len());

        if idx1 == len1 && idx2 == len2 {
            return 0;
        }

        let memo_idx = idx1 * (len2 + 1) + idx2;
        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut res = i32::MAX;

        if idx1 < len1 && idx2 < len2 && bytes1[idx1] == bytes2[idx2] {
            res = res.min(Self::dfs(bytes1, idx1 + 1, bytes2, idx2 + 1, memo));
        } else {
            if idx1 < len1 { 
                res = res.min(bytes1[idx1] as i32 + Self::dfs(bytes1, idx1 + 1, bytes2, idx2, memo));
            }

            if idx2 < len2 { 
                res = res.min(bytes2[idx2] as i32 + Self::dfs(bytes1, idx1, bytes2, idx2 + 1, memo));
            }
        }

        memo[memo_idx] = res;
        res
    }

    pub fn minimum_delete_sum(s1: String, s2: String) -> i32 {
        let (bytes1, bytes2) = (s1.as_bytes(), s2.as_bytes());
        let mut memo = vec![-1_i32; (bytes1.len() + 1) * (bytes2.len()  + 1)];

        Self::dfs(bytes1, 0, bytes2, 0, &mut memo)
    }
}
