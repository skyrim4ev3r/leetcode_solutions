impl Solution {
    const directions: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs_recursive(grid: &mut [Vec<i32>], i: usize, j: usize, rows: usize, cols: usize) -> i64 {

        if i >=  rows || j >= cols || grid[i][j] == 0 {
            return 0;
        }

        let mut sum = grid[i][j] as i64;
        grid[i][j] = 0;

        for (dx, dy) in Self::directions.iter() {
            sum += Self::dfs_recursive(grid, (i as isize + *dx) as usize, (j as isize + *dy) as usize, rows, cols);
        }

        sum
    }

    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {

        let mut count = 0;
        let rows = grid.len();
        let cols = grid[0].len();
        let k_i64 = k as i64;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] != 0 {
                    let mut sum = Self::dfs_recursive(&mut grid, i, j, rows, cols);

                    if sum % k_i64 == 0 {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
