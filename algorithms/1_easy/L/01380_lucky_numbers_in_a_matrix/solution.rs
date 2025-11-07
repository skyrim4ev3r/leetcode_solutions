impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = matrix.len();
        let cols = matrix[0].len();

        let mut rows_min_vals: Vec<i32> = Vec::with_capacity(rows);
        let mut cols_max_vals: Vec<i32> = Vec::with_capacity(cols);
        let mut res: Vec<i32> = Vec::new();

        for j in 0..cols {
            let mut max = i32::MIN;
            for i in 0..rows {
                max = max.max(matrix[i][j]);
            }
            cols_max_vals.push(max);
        }

        for i in 0..rows {
            let mut min = i32::MAX;
            for j in 0..cols {
                min = min.min(matrix[i][j]);
            }
            rows_min_vals.push(min);
        }

        for i in 0..rows {
            for j in 0..cols {
                if matrix[i][j] == rows_min_vals[i] && matrix[i][j] == cols_max_vals[j] {
                    res.push(matrix[i][j]);
                }
            }
        }

        res
    }
}
