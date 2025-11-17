impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs(grid: &mut Vec<Vec<i32>>, rows: usize, cols: usize, i: usize, j: usize) -> i32 {
        if i >= rows || j >= cols || grid[i][j] == 0 {
            return 1;
        }

        if grid[i][j] == -1 {
            return 0;
        }

        grid[i][j] = -1;
        let mut curr_perimeter = 0_i32;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;
            curr_perimeter += Self::dfs(grid, rows, cols, new_i, new_j);
        }

        curr_perimeter
    }

    pub fn island_perimeter(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut perimeter = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    return Self::dfs(&mut grid, rows, cols, i, j);
                }
            }
        }

        0
    }
}
