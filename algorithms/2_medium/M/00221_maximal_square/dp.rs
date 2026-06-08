impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        debug_assert!(matrix.len() > 0 && matrix[0].len() > 0);
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut dp = vec![0_i32; 2 * (cols + 1)];
        let (mut curr, mut next) = dp.split_at_mut(cols + 1);
        let mut max_side = 0;

        for i in (0..rows).rev() {
            for j in (0..cols).rev() {
                if matrix[i][j] == '1' {
                    curr[j] = 1 + next[j + 1].min(next[j]).min(curr[j + 1]);
                    max_side = max_side.max(curr[j]);
                }
            }

            (curr, next) = (next, curr);
            curr[..].fill(0);
        }

        max_side.pow(2)
    }
}
