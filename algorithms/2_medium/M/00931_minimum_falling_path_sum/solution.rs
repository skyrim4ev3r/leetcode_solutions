impl Solution {
    pub fn min_falling_path_sum(mut matrix: Vec<Vec<i32>>) -> i32 {
        let n = matrix.len();

        if n == 1 {
            return matrix[0][0];
        }

        for i in (0..(n - 1)).rev() {
            for j in 0..n {
                let mut min = matrix[i + 1][j];

                if j > 0 {
                    min = min.min(matrix[i + 1][j - 1]);
                }

                if j + 1 < n {
                    min = min.min(matrix[i + 1][j + 1]);
                }

                matrix[i][j] += min;
            }
        }

        *matrix[0].iter().min().unwrap()
    }
}
