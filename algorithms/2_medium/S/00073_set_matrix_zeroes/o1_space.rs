impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let should_first_row_set_zero = (0..cols).into_iter().any(|j| matrix[0][j] == 0);
        let should_first_col_set_zero = (0..rows).into_iter().any(|i| matrix[i][0] == 0);

        for i in 1..rows {
            for j in 1..cols {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..rows {
            for j in 1..cols {
                if matrix[i][0] == 0 || matrix[0][j] == 0 {
                    matrix[i][j] = 0;
                }
            }
        }

        if should_first_col_set_zero {
            for i in 0..rows {
                matrix[i][0] = 0;
            }
        }

        if should_first_row_set_zero {
            for j in 0..cols {
                matrix[0][j] = 0;
            }
        }
    }
}
