impl Solution {
    fn dfs(bytes: &[u8], len: isize, lo: isize, hi: isize, memo: &mut [i32]) -> i32 {
        if lo < 0 || hi >= len {
            return 0;
        }

        let memo_idx = (lo * len + hi) as usize;

        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let res = if bytes[lo as usize] == bytes[hi as usize] {
            2 + Self::dfs(bytes, len, lo - 1, hi + 1, memo)
        } else {
            Self::dfs(bytes, len, lo, hi + 1, memo).max(Self::dfs(bytes, len, lo - 1, hi, memo))
        };

        memo[memo_idx] = res;
        res
    }

    pub fn longest_palindrome_subseq(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = s.len() as isize;
        let mut memo = vec![-1_i32; (len * len) as usize];
        let mut max_palindrom = 0_i32;

        for i in 0..len {
            max_palindrom = max_palindrom
                           .max(1 + Self::dfs(bytes, len, i - 1, i + 1, &mut memo))
                           .max(Self::dfs(bytes, len, i - 1, i, &mut memo));
        }

        max_palindrom
    }
}
