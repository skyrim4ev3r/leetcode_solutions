impl Solution {
    const WATER: char = '0';
    const LAND: char = '1';
    const LAND_VISITED: char = '2';

    fn dfs(grid: &mut Vec<Vec<char>>, rows: isize, cols: isize, i: isize, j : isize) {
        if i < 0 || j < 0 || i >= rows || j >= cols || grid[i as usize][j as usize] != Self::LAND {
            return;
        }

        grid[i as usize][j as usize] = Self::LAND_VISITED;

        Self::dfs(grid, rows, cols, i + 1, j);
        Self::dfs(grid, rows, cols, i - 1, j);
        Self::dfs(grid, rows, cols, i, j + 1);
        Self::dfs(grid, rows, cols, i, j - 1);
    }

    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut count = 0_i32;
        let rows = grid.len() as isize;
        let cols = grid[0].len() as isize;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i as usize][j as usize] == Self::LAND {
                    count += 1;
                    Self::dfs(&mut grid, rows, cols, i, j);
                }
            }
        }

        count
    }
}
