impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut dp = vec![vec![0_i32; cols + 1]; rows + 1];
        let mut count = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if matrix[i][j] == 1 {
                    dp[i + 1][j + 1] = 1 + dp[i + 1][j].min(dp[i][j + 1]).min(dp[i][j]);
                    count += dp[i + 1][j + 1];
                }
            }
        }

        count
    }
}
