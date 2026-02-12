impl Solution {

    #[inline(always)]
    fn init_prefix_mat(matrix: &Vec<Vec<i32>>, rows: &usize, cols: &usize) -> Vec<Vec<(i32, i32)>> {
        let mut prefix = vec![vec![(0_i32, 0_i32); *cols]; *rows];
        prefix[0][0] = if matrix[0][0] == 1 { (1, 1) } else { (0, 0) };

        for i in 1..*rows {
            prefix[i][0].0 = prefix[i - 1][0].0 + matrix[i][0];
            prefix[i][0].1 = matrix[i][0];
        }

        for j in 1..*cols {
            prefix[0][j].0 = matrix[0][j];
            prefix[0][j].1 = prefix[0][j - 1].1 + matrix[0][j];
        }

        for i in 1..*rows {
            for j in 1..*cols {
                prefix[i][j].0 = prefix[i - 1][j].0 + matrix[i][j];
                prefix[i][j].1 = prefix[i][j - 1].1 + matrix[i][j];
            }
        }

        prefix
    }

    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let prefix = Self::init_prefix_mat(&matrix, &rows, &cols);
        let mut count = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if matrix[i][j] == 1 {
                    count += 1;

                    let mut next_i = i + 1;
                    let mut next_j = j + 1;

                    while next_i < rows && next_j < cols {
                        let traget_sum = (next_i - i + 1) as i32;
                        let prefix_rows = prefix[next_i][next_j].0 - if i > 0 { prefix[i - 1][next_j].0 } else { 0 };
                        let prefix_cols = prefix[next_i][next_j].1 - if j > 0 { prefix[next_i][j - 1].1 } else { 0 };

                        if prefix_rows != traget_sum || prefix_cols != traget_sum {
                            break;
                        }

                        count += 1;
                        next_i += 1;
                        next_j += 1;
                    }
                }
            }
        }

        count
    }
}
