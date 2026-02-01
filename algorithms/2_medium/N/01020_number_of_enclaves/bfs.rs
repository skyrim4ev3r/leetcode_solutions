use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (1, 0), (-1, 0), (0, -1)];

    #[inline(always)]
    fn init_q(
        grid: &mut Vec<Vec<i32>>,
        rows: usize,
        cols: usize,
    ) -> VecDeque<(usize, usize)> {
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..rows {
            if grid[i][0] == 1 {
                q.push_back((i, 0));
                grid[i][0] = 0;
            }

            if grid[i][cols - 1] == 1 {
                q.push_back((i, cols - 1));
                grid[i][cols - 1] = 0;
            }
        }

        for j in 0..cols {
            if grid[0][j] == 1 {
                q.push_back((0, j));
                grid[0][j] = 0;
            }

            if grid[rows - 1][j] == 1 {
                q.push_back((rows - 1, j));
                grid[rows - 1][j] = 0;
            }
        }

        q
    }

    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut q = Self::init_q(&mut grid, rows, cols); 

        while let Some((i, j)) = q.pop_front() {
            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || grid[new_i][new_j] == 0 {
                    continue;
                }

                grid[new_i][new_j] = 0;
                q.push_back((new_i, new_j));
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
