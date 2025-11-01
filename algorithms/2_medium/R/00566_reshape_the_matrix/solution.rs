impl Solution {
    pub fn matrix_reshape(mut mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {

        let original_rows = mat.len();
        let original_cols = mat[0].len();

        let target_rows = r as usize;
        let target_cols = c as usize;

        if (original_rows * original_cols != target_rows * target_cols)
            || (original_rows == target_rows && original_cols == target_cols)
        {
            return mat;
        }

        let mut res = vec![vec![0_i32; target_cols]; target_rows];

        let mut tmp: Vec<i32> = Vec::new();

        for i in (0..target_rows).rev() {
            for j in (0..target_cols).rev() {

                if tmp.is_empty() {
                    tmp = mat.pop().unwrap();
                }

                res[i][j] = tmp.pop().unwrap();
            }
        }

        res
    }
}
