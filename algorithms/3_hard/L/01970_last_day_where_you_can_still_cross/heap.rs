use std::collections::BinaryHeap;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    pub fn latest_day_to_cross(row: i32, col: i32, cells: Vec<Vec<i32>>) -> i32 {
        let rows = row as usize;
        let cols = col as usize;
        let mut mat = vec![vec![i32::MAX; cols]; rows];
        let mut visited = vec![vec![false; cols]; rows];
        let mut heap: BinaryHeap<(i32, usize, usize)> = BinaryHeap::new();

        for (i, cell) in cells.into_iter().enumerate() {
            mat[(cell[0] - 1) as usize][(cell[1] - 1) as usize] = (i + 1) as i32;
        }

        for j in 0..cols {
            heap.push((mat[0][j], 0, j));
            visited[0][j] = true;
        }
        

        while let Some((curr_day, i, j)) = heap.pop() {
            if i == rows - 1 {
                return curr_day - 1;
            }

            for (dx, dy) in Self::DIRECTIONS.iter() {
                let new_i = (i as isize + dx) as usize;
                let new_j = (j as isize + dy) as usize;

                if new_i >= rows || new_j >= cols || visited[new_i][new_j] {
                    continue;
                }

                let new_day = curr_day.min(mat[new_i][new_j]);
                visited[new_i][new_j] = true;
                heap.push((new_day, new_i, new_j));
            }
        }

        unreachable!()
    }
}
