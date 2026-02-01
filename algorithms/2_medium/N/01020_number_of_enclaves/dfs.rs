use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (1, 0), (-1, 0), (0, -1)];

    fn dfs(
        grid: &mut Vec<Vec<i32>>,
        rows: usize,
        cols: usize,
        i: usize,
        j: usize,
    ) {
        if i >= rows || j >= cols || grid[i][j] == 0 {
            return;
        }

        grid[i][j] = 0;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            Self::dfs(grid, rows, cols, new_i, new_j);
        }
    }

    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        
        for i in 0..rows {
            if grid[i][0] == 1 {
                Self::dfs(&mut grid, rows, cols, i, 0);
            }

            if grid[i][cols - 1] == 1 {
                Self::dfs(&mut grid, rows, cols, i, cols - 1);
            }
        }

        for j in 0..cols {
            if grid[0][j] == 1 {
                Self::dfs(&mut grid, rows, cols, 0, j);
            }

            if grid[rows - 1][j] == 1 {
                Self::dfs(&mut grid, rows, cols, rows - 1, j);
            }
        }

        let mut count = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    count += 1;
                }
            }
        }

        count
    }
}
