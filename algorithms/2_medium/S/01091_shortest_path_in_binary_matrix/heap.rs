use std::collections::BinaryHeap;

impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [(1, -1), (1, 0), (1, 1), (0, 1), (0, -1), (-1, -1), (-1, 0), (-1, 1)];

    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {
        if grid[0][0] == 1 {
            return -1;
        }

        let rows = grid.len();
        let cols = grid[0].len();

        if rows == 1 && cols == 1 {
            return 1;
        }

        let mut is_visited = vec![vec![false; cols]; rows];
        let mut heap: BinaryHeap<(i32, usize, usize)> = BinaryHeap::new();

        is_visited[0][0] = true;
        heap.push((-1, 0, 0));

        while let Some((old_cost, i, j)) = heap.pop() {
            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                if grid[new_i][new_j] == 1 || is_visited[new_i][new_j] {
                    continue;
                }

                if new_i == rows - 1 && new_j == cols - 1 {
                    return (old_cost - 1).abs();
                }

                is_visited[new_i][new_j] = true;
                heap.push((old_cost - 1, new_i, new_j));
            }
        }

        -1
    } 
}
