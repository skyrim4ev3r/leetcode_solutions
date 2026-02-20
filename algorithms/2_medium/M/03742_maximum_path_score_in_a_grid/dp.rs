impl Solution {
    pub fn max_path_score(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let k_usize = k as usize;
        let mut dp = vec![vec![vec![-1_i32; k_usize + 1]; cols]; rows];
        dp[0][0][0] = 0;

        for i in 0..rows {
            for j in 0..cols {
                let score_cell = grid[i][j];
                let cost_cell = if score_cell != 0 { 1_usize } else { 0_usize };

                if i > 0 {
                    for c in 0..=k_usize {
                        if dp[i - 1][j][c] != -1 {
                            if c + cost_cell <= k_usize {
                                dp[i][j][c + cost_cell] = dp[i][j][c + cost_cell].max(dp[i - 1][j][c] + score_cell);
                            }
                        }
                    }
                }

                if j > 0 {
                    for c in 0..=k_usize {
                        if dp[i][j - 1][c] != -1 {
                            if c + cost_cell <= k_usize {
                                dp[i][j][c + cost_cell] = dp[i][j][c + cost_cell].max(dp[i][j - 1][c] + score_cell);
                            }
                        }
                    }
                }
            }
        }

        dp[rows - 1][cols - 1].iter().map(|x| *x).max().unwrap()
    }
}
