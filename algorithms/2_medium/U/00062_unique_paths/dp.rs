impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let rows = m.max(n) as usize;
        let cols = m.min(n) as usize;
        let mut dp = vec![1_i32; cols];
        let mut dp_next = vec![0_i32; cols];

        for _ in 1..rows {
            dp_next[0] = 1;
            for j in 1..cols {
                dp_next[j] = dp_next[j - 1] + dp[j];
            }
            std::mem::swap(&mut dp, &mut dp_next);
        }

        dp[cols - 1]
    }
}
