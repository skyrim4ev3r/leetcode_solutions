impl Solution {
    pub fn number_of_right_triangles(grid: Vec<Vec<i32>>) -> i64 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut prefix_cols = vec![0_i32; cols];
        let mut prefix_rows = vec![0_i32; rows];
        let mut count = 0_i64;

        for i in 0..rows {
            for j in 0..cols {
                prefix_cols[j] += grid[i][j];
                prefix_rows[i] += grid[i][j];
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    count += (prefix_rows[i] as i64 - 1) * (prefix_cols[j] as i64 - 1);
                }
            }
        }

        count
    }
}
