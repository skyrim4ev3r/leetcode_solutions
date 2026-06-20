impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let dp_rows = rows + 1;
        let dp_cols = cols + 1;
        let mut dp = vec![0_i32; dp_rows * dp_cols];
        let mut count = 0_i32;

        for i in (0..rows).rev() {
            for j in (0..cols).rev() {
                if matrix[i][j] == 1 {
                    let r = dp[i * dp_cols + j + 1];
                    let d = dp[(i + 1) * dp_cols + j];
                    let rd = dp[(i + 1) * dp_cols + j + 1];

                    dp[i * dp_cols + j] = 1 + r.min(d).min(rd);
                    count += dp[i * dp_cols + j];
                }
            }
        }

        count
    }
}
