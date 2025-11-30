impl Solution {
    pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut res = vec![vec![0_i32; rows]; cols];

        for j in 0..cols {
            for i in 0..rows {
                res[j][i] = matrix[i][j];
            }
        }

        res
    }
}
