impl Solution {
    pub fn matrix_block_sum(mut mat: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let rows = mat.len();
        let cols = mat[0].len();
        let k = k as usize;
        let mut res = vec![vec![0; cols]; rows];

        for i in 0..rows {
            for j in 1..cols {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for j in 0..cols {
            for i in 1..rows {
                mat[i][j] += mat[i - 1][j];
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                let start_i = i.max(k) - k;
                let start_j = j.max(k) - k;

                let end_i = (i + k).min(rows - 1);
                let end_j = (j + k).min(cols - 1);

                res[i][j] = mat[end_i][end_j];

                if start_j > 0 {
                    res[i][j] -= mat[end_i][start_j - 1];
                }

                if start_i > 0 {
                    res[i][j] -= mat[start_i - 1][end_j];
                }

                if start_i > 0 && start_j > 0 {
                    res[i][j] += mat[start_i - 1][start_j - 1];
                }
            }
        }

        res
    }
}
