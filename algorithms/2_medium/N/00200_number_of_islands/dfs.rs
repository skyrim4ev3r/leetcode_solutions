impl Solution {
    // Using usize::MAX as -1
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    fn dfs(grid: &mut Vec<Vec<char>>, rows: usize, cols: usize, i: usize, j: usize) {
        if grid[i][j] == '0' {
            return;
        }

        grid[i][j] = '0';

        for &(dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            if new_i >= rows || new_j >= cols {
                continue;
            }

            Self::dfs(grid, rows, cols, new_i, new_j);
        }
    }

    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        
        let rows = grid.len();
        let cols = grid[0].len();

        let mut count = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == '1' {
                    count += 1;
                    Self::dfs(&mut grid, rows, cols, i, j);
                }
            }
        }

        count
    }
}
