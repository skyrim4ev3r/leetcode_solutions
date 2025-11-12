use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [(1, -1), (1, 0), (1, 1), (0, 1), (0, -1), (-1, -1), (-1, 0), (-1, 1)];

    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {
        if grid[0][0] == 1 {
            return -1;
        }

        let rows = grid.len();
        let cols = grid[0].len();
        let mut costs = vec![vec![i32::MAX; cols]; rows];
        let mut deque = VecDeque::new();

        costs[0][0] = 1;
        deque.push_back((0, 0));

        while let Some((i, j)) = deque.pop_front() {
            let old_cost = costs[i][j];

            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                if grid[new_i][new_j] == 1 || costs[new_i][new_j] <= old_cost + 1 {
                    continue;
                }

                costs[new_i][new_j] = old_cost + 1;

                deque.push_back((new_i, new_j));
            }
        }

        if costs[rows - 1][cols - 1] == i32::MAX {
            return -1;
        }

        costs[rows - 1][cols - 1]
    } 
}
