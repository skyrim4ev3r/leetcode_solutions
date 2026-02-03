use std::collections::BinaryHeap;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn minimum_effort_path(heights: Vec<Vec<i32>>) -> i32 {
        let rows = heights.len();
        let cols = heights[0].len();
        let mut costs = vec![vec![i32::MAX; cols]; rows];
        let mut heap: BinaryHeap<(i32, u8, u8)> = BinaryHeap::new();
        heap.push((0, 0, 0));

        while let Some((negative_cost, i_u8, j_u8)) = heap.pop() {
            let (cost, i, j) = (-negative_cost, i_u8 as usize, j_u8 as usize);

            if i == rows - 1 && j == cols - 1 {
                return cost;
            }

            if cost > costs[i][j] {
                continue;
            }

            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                let move_cost = (heights[i][j] - heights[new_i][new_j]).abs();
                let new_cost = move_cost.max(cost);

                if new_cost >= costs[new_i][new_j] {
                    continue;
                }

                costs[new_i][new_j] = new_cost;

                heap.push((-new_cost, new_i as u8, new_j as u8));
            }
        }

        unreachable!()
    }
}
