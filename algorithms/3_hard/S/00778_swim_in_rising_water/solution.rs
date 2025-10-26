use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, PartialEq, Eq)]
struct Cell {
    cost: i32,
    i: usize,
    j: usize,
}

impl Ord for Cell {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.cost.cmp(&self.cost) // Compare in reverse
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();

        if n <= 1 {
            return 0;
        }

        let n_i32 = n as i32;
        let mut is_visited = vec![vec![false; n]; n];
        let directions: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, -1), (0,1)];
        let mut heap: BinaryHeap<Cell> = BinaryHeap::new();

        heap.push(Cell{cost: grid[0][0], i: 0, j: 0});
        is_visited[0][0] = true;

        while let Some(cell) = heap.pop() {
            for &(dx, dy) in directions.iter() {
                let new_i = (cell.i as isize + dx) as usize;
                let new_j = (cell.j as isize + dy) as usize;

                if new_i >= n || new_j >= n || is_visited[new_i][new_j] {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                let new_cost = grid[new_i][new_j].max(cell.cost);

                if new_i == n - 1 && new_j == n - 1 {
                    return new_cost;
                }

                heap.push(Cell{cost: new_cost, i: new_i, j: new_j});
            }
        }

        -1
    }
}
