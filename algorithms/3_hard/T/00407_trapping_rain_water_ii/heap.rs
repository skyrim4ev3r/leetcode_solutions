use std::collections::BinaryHeap;

#[derive(Eq, PartialEq)]
struct Cell {
    height: i32,
    i: usize,
    j: usize,
}

impl Ord for Cell {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.height.cmp(&self.height)
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        let m = height_map.len();
        let n = height_map[0].len();
        let mut heap:BinaryHeap<Cell> = BinaryHeap::new();
        let mut is_visited = vec![vec![false; n]; m];

        for i in 0..m {
            for j in 0..n {
                if i == 0 || i == m - 1 || j == 0 || j == n - 1 {
                    is_visited[i][j] = true;
                    heap.push(Cell{height: height_map[i][j], i, j});
                }
            }
        }

        let mut sum = 0_i32;
        let directions: [(isize, isize); 4]= [(-1, 0), (0, -1), (1, 0), (0, 1)];

        while let Some(cell) = heap.pop() {

            let old_j = cell.j;
            let old_i = cell.i;
            let old_height = cell.height;

            for (dx, dy) in directions.iter() {
                let new_i = (old_i as isize + *dx) as usize;
                let new_j = (old_j as isize + *dy) as usize;

                if new_i >= m || new_j >= n || is_visited[new_i][new_j] {
                    continue;
                }

                let new_height = height_map[new_i][new_j];
                sum += (old_height - new_height).max(0);
                is_visited[new_i][new_j] = true;
                heap.push(Cell{height: new_height.max(old_height), i: new_i, j: new_j});
            }
        }

        sum
    }
}
