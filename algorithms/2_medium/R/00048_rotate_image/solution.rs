impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        let n_half = n / 2;

        for i in 0..n_half {
            let start_j = i;
            let end_j = n - i - 1;

            for j in start_j..end_j {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] =  matrix[n - 1 - i][n - 1 -j];
                matrix[n - 1 - i][n - 1 -j] =  matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
}
