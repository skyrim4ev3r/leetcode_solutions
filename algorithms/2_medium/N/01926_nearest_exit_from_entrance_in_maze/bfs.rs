use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn nearest_exit(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let mut cost_queue: VecDeque<(i32, usize, usize)> = VecDeque::new();
        let rows = maze.len();
        let cols = maze[0].len();
        let start_i = entrance[0] as usize;
        let start_j = entrance[1] as usize;
        let mut is_visited = vec![vec![false; cols]; rows];

        cost_queue.push_back((0, start_i, start_j));
        is_visited[start_i][start_j] = true;

        while let Some((curr_cost, curr_i, curr_j)) = cost_queue.pop_front() {
            let new_cost = curr_cost + 1;
            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (curr_i as isize + *dx) as usize;
                let new_j = (curr_j as isize + *dy) as usize;

                if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] || maze[new_i][new_j] == '+' {
                    continue;
                }

                if new_i == rows - 1 || new_j == cols - 1 || new_i == 0 || new_j == 0 {
                    return new_cost;
                }
                
                is_visited[new_i][new_j] = true;
                cost_queue.push_back((new_cost, new_i, new_j));
            }
        }

        -1
    }
}
