impl Solution {
    const MOD_TO: i32 = 1_000_000_007;

    pub fn number_of_paths(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![vec![0_i32; k as usize]; n]; m];

        dp[0][0][(grid[0][0] % k) as usize] = 1;

        for i in 1..m {
            let val = grid[i][0];

            for t in 0..k {
                dp[i][0][((t + val) % k) as usize] = dp[i - 1][0][t as usize];
            }
        }

        for j in 1..n {
            let val = grid[0][j];

            for t in 0..k {
                dp[0][j][((t + val) % k) as usize] = dp[0][j - 1][t as usize];
            }
        }

        for i in 1..m {
            for j in 1.. n {
                let val = grid[i][j];

                for t in 0..k {
                    dp[i][j][((t + val) % k) as usize] = (dp[i][j - 1][t as usize] + dp[i - 1][j][t as usize]) % Self::MOD_TO;
                }
            }
        }

        dp[m - 1][n - 1][0]
    }
}
