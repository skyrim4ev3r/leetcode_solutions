impl Solution {
    const directions: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs_iterative(grid: &mut [Vec<i32>], i: usize, j: usize, rows: usize, cols: usize) -> i64 {

        let mut sum = grid[i][j] as i64;
        grid[i][j] = 0;
        let mut stack = vec![(i, j)];

        while let Some((old_i, old_j)) = stack.pop() {
            for (dx, dy) in Self::directions.iter() {
                let new_i = (old_i as isize + *dx) as usize;
                let new_j = (old_j as isize + *dy) as usize;

                if new_i >=  rows || new_j >= cols || grid[new_i][new_j] == 0 { 
                    continue;
                }

                sum += grid[new_i][new_j] as i64;
                grid[new_i][new_j] = 0;
                stack.push((new_i, new_j));
            }
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
                    let sum = Self::dfs_iterative(&mut grid, i, j, rows, cols);

                    if sum % k_i64 == 0 {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
