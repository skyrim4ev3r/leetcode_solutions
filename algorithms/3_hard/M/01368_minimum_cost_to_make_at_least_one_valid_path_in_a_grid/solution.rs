use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug)]
struct Cell {
    cost: i32,
    i: usize,
    j: usize,
}

impl Eq for Cell {}

impl PartialEq for Cell {
    fn eq(&self, other: &Self) -> bool {
        self.i == other.i && self.j == other.j
    }
}

impl Ord for Cell {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();

        const directions: [(isize, isize); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut cost_matrix = vec![vec![i32::MAX; cols]; rows];
        let mut heap: BinaryHeap<Cell> = BinaryHeap::new();

        heap.push(Cell { cost: 0, i: 0, j: 0 });
        cost_matrix[0][0] = 0;

        while let Some(cell) = heap.pop() {
            if cell.i == rows - 1 && cell.j == cols - 1 {
                return cell.cost;
            }

            for (index, (dx, dy)) in directions.iter().enumerate() {
                let new_i = (cell.i as isize + *dx) as usize;
                let new_j = (cell.j as isize + *dy) as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                let new_cost = cell.cost + if index == (grid[cell.i][cell.j] - 1) as usize { 0 } else { 1 };

                if new_cost < cost_matrix[new_i][new_j] {
                    cost_matrix[new_i][new_j] = new_cost;
                    heap.push(Cell { cost: new_cost, i: new_i, j: new_j });
                }                
            }
        }

        -1
    }
}

