impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut perimeter = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    if i == 0 || grid[i - 1][j] == 0 {
                        perimeter += 1;
                    }

                    if i == rows - 1 || grid[i + 1][j] == 0 {
                        perimeter += 1;
                    }

                    if j == 0 || grid[i][j - 1] == 0 {
                        perimeter += 1;
                    }

                    if j == cols - 1 || grid[i][j + 1] == 0 {
                        perimeter += 1;
                    }
                }
            }
        }

        perimeter
    }
}
