impl Solution {
    const directions: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, count: &mut i32) {
        if i >= grid.len() || j >= grid[0].len() || grid[i][j] == 0 {
            return;
        }

        *count += 1;
        grid[i][j] = 0;

        for (dx, dy) in Self::directions.iter() {
            let new_i = (i as isize + *dx) as usize;
            let new_j = (j as isize + *dy) as usize;
            Self::dfs(grid, new_i, new_j, count);
        }
    }

    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut max = 0;
        let rows = grid.len();
        let cols = grid[0].len();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    let mut count = 0;
                    Self::dfs(&mut grid, i, j, &mut count);
                    max = max.max(count);
                }
            }
        }

        max
    }
}
