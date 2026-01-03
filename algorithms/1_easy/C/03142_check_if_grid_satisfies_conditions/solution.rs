impl Solution {
    pub fn satisfies_conditions(grid: Vec<Vec<i32>>) -> bool {
        let rows = grid.len();
        let cols = grid[0].len();

        for j in 0..cols {
            for i in 0..rows {
                if (i > 0 && grid[i][j] != grid[i - 1][j]) || (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    return false;
                }
            }
        }

        true
    }
}
