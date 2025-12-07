impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let (rows, cols) = (m as usize, n as usize);
        let mut dp = vec![vec![0_i32; cols]; rows];
        dp[0][0] = 1;

        for i in 0..rows {
            for j in 0..cols {
                if i > 0 {
                    dp[i][j] += dp[i - 1][j];
                }

                if j > 0 {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        dp[rows - 1][cols - 1]
    }
}
