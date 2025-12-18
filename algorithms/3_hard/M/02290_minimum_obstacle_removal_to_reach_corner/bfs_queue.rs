use std::collections::VecDeque;

impl Solution {
    pub fn minimum_obstacles(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut cost_matrix = vec![vec![i32::MAX; cols]; rows];
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();

        cost_matrix[0][0] = grid[0][0];
        queue.push_back((0, 0));

        const DIRECTIONS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        while let Some((i, j)) = queue.pop_front() {
            for (dx, dy) in DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                let new_cost = cost_matrix[i][j] + grid[new_i][new_j];

                if new_cost < cost_matrix[new_i][new_j] {
                    cost_matrix[new_i][new_j] = new_cost;
                    queue.push_back((new_i, new_j));
                }
            }
        }

        cost_matrix[rows - 1][cols - 1]
    }
}
