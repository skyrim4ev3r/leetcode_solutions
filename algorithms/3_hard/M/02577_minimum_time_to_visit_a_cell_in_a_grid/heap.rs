use std::collections::BinaryHeap;

impl Solution {
    pub fn minimum_time(grid: Vec<Vec<i32>>) -> i32 {
        const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];
        let mut heap: BinaryHeap<(i32, usize, usize)> = BinaryHeap::new();
        let rows = grid.len();
        let cols = grid[0].len();
        let mut is_visited = vec![vec![false; cols]; rows];

        if grid[0][1] > 1 && grid[1][0] > 1 {
            return -1;
        }

        heap.push((0, 0, 0));
        is_visited[0][0] = true;

        while let Some((old_cost_negative, old_i, old_j)) = heap.pop() {
            let old_cost = old_cost_negative.abs();

            for (dx, dy) in DIRECTIONS.iter() {
                let new_i = (old_i as isize + dx) as usize;
                let new_j = (old_j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] {
                    continue;
                }

                let grid_val = grid[new_i][new_j];
                let new_cost = if old_cost + 1 >= grid_val {old_cost + 1} else {grid_val + ((grid_val - (old_cost + 1)) & 1)};

                if new_i == rows - 1 && new_j == cols - 1 {
                    return new_cost.abs();
                }

                is_visited[new_i][new_j] = true;
                heap.push((-new_cost, new_i, new_j));
            }
        }

        -1
    }
}
