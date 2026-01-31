impl Solution {
    pub fn min_flips(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut row_cost = 0_i32;
        let mut col_cost = 0_i32;

        for i in 0..(rows / 2) {
            let other_i = rows - 1 - i;

            for j in 0..cols {
                if grid[i][j] != grid[other_i][j] {
                    row_cost += 1;
                }
            }
        }

        for j in 0..(cols / 2) {
            let other_j = cols - 1 - j;

            for i in 0..rows {
                if grid[i][j] != grid[i][other_j] {
                    col_cost += 1;
                }
            }
        }

        col_cost.min(row_cost)
    }
}
