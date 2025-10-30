impl Solution {
    pub fn max_sum(grid: Vec<Vec<i32>>) -> i32 {
        let mut max_sum = 0;
        let rows = grid.len();
        let cols = grid[0].len();

        for i in 0..(rows - 2) {
            for j in 0..(cols - 2) {
                let sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + 
                            grid[i + 1][j + 1] + 
                          grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                max_sum = max_sum.max(sum);
            }
        }

        max_sum
    }
}
