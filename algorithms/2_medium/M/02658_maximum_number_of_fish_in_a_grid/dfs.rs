impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs(grid: &mut Vec<Vec<i32>>, rows: usize, cols: usize, i: usize, j:usize) -> i32 {
        if i >= rows || j >= cols || grid[i][j] == 0 {
            return 0;
        }

        let mut sum = grid[i][j];
        grid[i][j] = 0;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            sum += Self::dfs(grid, rows, cols, new_i, new_j);
        }

        sum
    }
    pub fn find_max_fish(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut max = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] > 0 {
                    max = max.max(Self::dfs(&mut grid, rows, cols, i, j));
                }
            }
        }

        max
    }
}
