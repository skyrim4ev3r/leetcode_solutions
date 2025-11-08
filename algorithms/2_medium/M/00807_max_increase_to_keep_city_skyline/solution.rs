impl Solution {
    pub fn max_increase_keeping_skyline(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();

        let mut max_rows: Vec<i32> = Vec::with_capacity(n);
        let mut max_cols: Vec<i32> = Vec::with_capacity(n);

        for i in 0..n {
            let mut max = 0_i32;

            for j in 0..n {
                max = max.max(grid[i][j]);
            }

            max_rows.push(max);
        }

        for j in 0..n {
            let mut max = 0_i32;

            for i in 0..n {
                max = max.max(grid[i][j]);
            }

            max_cols.push(max);
        }

        let mut count = 0_i32;

        for i in 0..n {
            for j in 0..n {
                count += max_cols[j].min(max_rows[i]) - grid[i][j];
            }
        }

        count
    }
}
