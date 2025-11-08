use std::collections::BinaryHeap;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let rows = move_time.len();
        let cols = move_time[0].len();

        let mut heap: BinaryHeap<(i32, usize, usize, bool)> = BinaryHeap::new();
        let mut is_visited = vec![vec![false; cols]; rows];
        heap.push((0, 0, 0, true));
        is_visited[0][0] = true;

        while let Some((cost, i, j, flip_flop)) = heap.pop() {
            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] {
                    continue;
                }

                is_visited[new_i][new_j] = true;
                let new_cost = cost.min(-move_time[new_i][new_j]) - if flip_flop {1} else {2};

                if new_i == rows - 1 && new_j == cols - 1 {
                    return new_cost.abs();
                }

                heap.push((new_cost, new_i, new_j, !flip_flop));
            }
        }

        -1
    }
}
