use std::sync::Mutex;

impl Solution {
    const MAX_ROWS: usize = 200;
    const MAX_COLS: usize = 200;
    const MAX_K: usize = 1_000;

    pub fn max_path_score(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let k_usize = k as usize;
        static DP: Mutex<[[[i32; Solution::MAX_K + 1]; Solution::MAX_COLS]; Solution::MAX_ROWS]> = {
            Mutex::new(
                [[[-1_i32; Solution::MAX_K + 1]; Solution::MAX_COLS]; Solution::MAX_ROWS]
            )
        };
        let mut dp = DP.lock().unwrap();
        for i in 0..rows {
            for j in 0..cols { 
                for c in 0..=k_usize {
                    dp[i][j][c] = -1;
                }
            }
        }
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

        dp[rows - 1][cols - 1].iter().take(k_usize + 1).map(|x| *x).max().unwrap()
    }
}
