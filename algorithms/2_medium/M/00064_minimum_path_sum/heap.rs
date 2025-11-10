use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct Cell {
    val: i32,
    i: usize,
    j: usize,
}

impl Ord for Cell {
    fn cmp(&self, other: &Self) -> Ordering {
        other.val.cmp(&self.val) // Reverse for min-heap
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();

        if rows == 1 && cols == 1 {
            return grid[0][0];
        }

        let mut min_heap: BinaryHeap<Cell> = BinaryHeap::new();
        let mut is_visited = vec![vec![false; cols]; rows];
        const directions: [(usize, usize); 2] = [(0, 1), (1, 0)];

        min_heap.push(Cell {val: grid[0][0], i: 0, j: 0});
        is_visited[0][0] = true;

        while let Some(cell) = min_heap.pop() {
            for (dx, dy) in directions.iter() {
                let new_i = cell.i + dx;
                let new_j = cell.j + dy;

                if new_j >= cols || new_i >= rows || is_visited[new_i][new_j] {
                    continue;
                }

                is_visited[new_i][new_j] = true;
                let new_val = grid[new_i][new_j] + cell.val;

                if new_i == rows - 1 && new_j == cols - 1 {
                    return new_val;
                }

                min_heap.push(Cell {val: new_val, i: new_i, j: new_j});
            }
        }

        -1
    }
}
