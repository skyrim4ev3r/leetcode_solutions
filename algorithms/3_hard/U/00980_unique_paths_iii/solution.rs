impl Solution {
    const directions: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

    fn dfs(grid: &mut Vec<Vec<i32>>, count: &mut i32, target_path_len: i32, curr_path_len: i32, i: usize, j:usize) {
        if i >= grid.len() || j >= grid[0].len() || grid[i][j] == -1 {
            return;
        }

        if grid[i][j] == 2 {
            if target_path_len == curr_path_len {
                *count += 1;
            }

            return;
        }

        grid[i][j] = -1;
        for &(dx, dy) in Self::directions.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;
            Self::dfs(grid, count, target_path_len, curr_path_len + 1, new_i, new_j);
        }
        grid[i][j] = 0;
    }

    pub fn unique_paths_iii(mut grid: Vec<Vec<i32>>) -> i32 {

        let mut target_path_len = 0;
        let rows = grid.len();
        let cols = grid[0].len();
        let mut start = (0_usize, 0_usize);

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 0 || grid[i][j] == 2 {
                    target_path_len += 1;
                }

                if grid[i][j] == 1 {
                    start = (i, j);
                }
            }
        }

        let mut count = 0_i32;
        Self::dfs(&mut grid, &mut count, target_path_len, 0, start.0, start.1);

        count
    }
}
