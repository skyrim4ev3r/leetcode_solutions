impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    fn dfs(
        grid: &Vec<Vec<i32>>,
        is_visited: &mut Vec<Vec<bool>>,
        rows: usize,
        cols: usize,
        i: usize,
        j: usize,
    ) {
        if i >= rows || j >= cols || grid[i][j] == 1 || is_visited[i][j] {
            return;
        }

        is_visited[i][j] = true;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            Self::dfs(grid, is_visited, rows, cols, new_i, new_j);
        }
    }

    pub fn closed_island(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut is_visited = vec![vec![false; cols]; rows];
        let mut count = 0_i32;

        for i in 0..rows {
            if grid[i][0] == 0 && is_visited[i][0] == false {
                Self::dfs(&grid, &mut is_visited, rows, cols, i, 0);
            }

            if grid[i][cols - 1] == 0 && is_visited[i][cols - 1] == false {
                Self::dfs(&grid, &mut is_visited, rows, cols, i, cols - 1);
            }
        }

        for j in 0..cols {
            if grid[0][j] == 0 && is_visited[0][j] == false {
                Self::dfs(&grid, &mut is_visited, rows, cols, 0, j);
            }

            if grid[rows - 1][j] == 0 && is_visited[rows - 1][j] == false {
                Self::dfs(&grid, &mut is_visited, rows, cols, rows - 1, j);
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 0 && is_visited[i][j] == false {
                    count += 1;
                    Self::dfs(&grid, &mut is_visited, rows, cols, i, j);
                }
            }
        }

        count
    }
}
