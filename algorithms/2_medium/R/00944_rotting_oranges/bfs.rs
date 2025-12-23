use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 2 {
                    q.push_back((i, j));
                }
            }
        }

        let mut count = 0_i32;

        while !q.is_empty() {
            let len = q.len();

            for _ in 0..len {
                let (i, j) = q.pop_front().unwrap();
                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + *dx) as usize;
                    let new_j = (j as isize + *dy) as usize;

                    if new_i >= rows || new_j >= cols || grid[new_i][new_j] != 1 {
                        continue;
                    }

                    grid[new_i][new_j] = 2;
                    q.push_back((new_i, new_j));
                }
            }

            if (!q.is_empty()) {
                count += 1;
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    return -1;
                }
            }
        }

        count
    }
}
