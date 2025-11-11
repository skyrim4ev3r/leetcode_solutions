impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut area = 0_i32;

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] > 0 {
                    area += 2; // for up and down area

                    for (dx, dy) in Self::DIRECTIONS.iter() {
                        let neighbor_i = (i as isize + dx) as usize;
                        let neighbor_j = (j as isize + dy) as usize;

                        let neighbor_h = if neighbor_i >= n || neighbor_j >= n {0_i32} else {grid[neighbor_i][neighbor_j]};
                         area += 0_i32.max(grid[i][j] - neighbor_h);
                    }
                }
            }
        }

        area
    }
}
