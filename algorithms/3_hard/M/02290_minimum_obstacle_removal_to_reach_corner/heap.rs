use std::collections::BinaryHeap;

impl Solution {
    pub fn minimum_obstacles(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut is_visited = vec![vec![false; cols]; rows];
        let mut heap: BinaryHeap<(i32, usize, usize)> = BinaryHeap::new();
        heap.push((-grid[0][0], 0, 0));
        is_visited[0][0] = true;
        const DIRECTIONS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        while let Some((old_cost_negative, i, j)) = heap.pop() {
            for (dx, dy) in DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] {
                    continue;
                }

                let new_cost = old_cost_negative.abs() + grid[new_i][new_j];

                if new_i == rows - 1 && new_j == cols - 1 {
                    return new_cost;
                }

                is_visited[new_i][new_j] = true;
                heap.push((-new_cost, new_i, new_j));
            }
        }

        -1
    }
}
