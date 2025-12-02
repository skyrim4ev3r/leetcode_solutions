impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = mat.len();
        let cols = mat[0].len();
        let mut temp: Vec<i32> = Vec::with_capacity(rows.max(cols));

        for start_j in 0..cols {
            let mut i = 0_usize;
            let mut j = start_j;

            while i < rows && j < cols {
                temp.push(mat[i][j]);
                i += 1;
                j += 1;
            }

            temp.sort_unstable();

            i = 0;
            j = start_j;

            while i < rows && j < cols {
                mat[i][j] = temp[i];
                i += 1;
                j += 1;
            }

            temp.clear();
        }

        for start_i in 1..rows {
            let mut i = start_i;
            let mut j = 0_usize;

            while i < rows && j < cols {
                temp.push(mat[i][j]);
                i += 1;
                j += 1;
            }

            temp.sort_unstable();

            i = start_i;
            j = 0;

            while i < rows && j < cols {
                mat[i][j] = temp[j];
                i += 1;
                j += 1;
            }

            temp.clear();
        }

        mat
    }
}
