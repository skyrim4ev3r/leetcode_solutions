impl Solution {
    const MOD_TO: i32 = 1_000_000_007;

    pub fn unique_paths(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![(0_i32, 0_i32); n]; m];
        dp[0][0] = (1, 1);

        for i in 1..m {
            if grid[i - 1][0] == 1 {
                break;
            }

            dp[i][0].1 = 1;
        }

        for j in 1..n {
            if grid[0][j - 1] == 1 {
                break;
            }

            dp[0][j].0 = 1;
        }

        for i in 1..m {
            for j in 1..n {
                if grid[i - 1][j] == 0 {
                    dp[i][j].1 = (dp[i][j].1 + dp[i - 1][j].0) % Self::MOD_TO;
                    dp[i][j].1 = (dp[i][j].1 + dp[i - 1][j].1) % Self::MOD_TO;
                } else {
                    dp[i][j].1 = (dp[i][j].1 + dp[i - 1][j].0) % Self::MOD_TO;
                }

                if grid[i][j - 1] == 0 {
                    dp[i][j].0 = (dp[i][j].0 + dp[i][j - 1].0) % Self::MOD_TO;
                    dp[i][j].0 = (dp[i][j].0 + dp[i][j - 1].1) % Self::MOD_TO;
                } else {
                    dp[i][j].0 = (dp[i][j].0 + dp[i][j - 1].1) % Self::MOD_TO;
                }
            }
        }

        (dp[m - 1][n - 1].0 +  dp[m - 1][n - 1].1) % Self::MOD_TO
    }
}
