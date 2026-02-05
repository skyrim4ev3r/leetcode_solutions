use std::collections::BinaryHeap;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn find_safe_walk(grid: Vec<Vec<i32>>, health: i32) -> bool {
        if health - grid[0][0] <= 0 {
            return false;
        }

        let rows = grid.len();
        let cols = grid[0].len();
        let mut heap: BinaryHeap<(i32, u8, u8)> = BinaryHeap::new();
        let mut visited = vec![vec![false; cols]; rows];
        visited[0][0] = true;
        heap.push((health - grid[0][0], 0, 0));

        while let Some((prev_health, i_i8, j_i8)) = heap.pop() {
            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i_i8 as isize + dx) as usize;
                let new_j = (j_i8 as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || visited[new_i][new_j] {
                    continue;
                }

                let new_health = prev_health - grid[new_i][new_j];

                if new_i == rows - 1 && new_j == cols - 1 {
                    return new_health > 0;
                }

                if new_health <= 0 {
                    continue;
                }

                visited[new_i][new_j] = true;
                heap.push((new_health, new_i as u8, new_j as u8));
            }
        }

        false
    }
}
