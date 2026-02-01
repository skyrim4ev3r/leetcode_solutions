use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn max_distance(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    q.push_back((i, j));
                }
            }
        }

        if q.is_empty() || q.len() == n * n {
            return -1;
        }

        let mut curr_level = 0_i32;

        while !q.is_empty() {
            let curr_len = q.len();
            curr_level += 1;

            for _ in 0..curr_len {
                let (i, j) = q.pop_front().unwrap();

                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + dx) as usize;
                    let new_j = (j as isize + dy) as usize;

                    if new_i >= n || new_j >= n || grid[new_i][new_j] == 1 {
                        continue;
                    }

                    grid[new_i][new_j] = 1;
                    q.push_back((new_i, new_j));
                }
            }
        }

        curr_level - 1
    }
}
