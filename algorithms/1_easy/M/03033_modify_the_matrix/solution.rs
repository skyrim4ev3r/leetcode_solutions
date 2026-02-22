impl Solution {
    pub fn modified_matrix(mut matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = matrix.len();
        let cols = matrix[0].len();

        for j in 0..cols {
            let mut max = i32::MIN;

            for i in 0..rows {
                max = max.max(matrix[i][j]);
            }

            for i in 0..rows {
                if matrix[i][j] == -1 {
                    matrix[i][j] = max;
                }
            }
        }

        matrix
    }
}
