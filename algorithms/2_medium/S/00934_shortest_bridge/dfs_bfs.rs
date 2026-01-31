use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (0, -1), (-1, 0)];

    fn dfs_calc_first_island(
        grid: &mut Vec<Vec<i32>>,
        rows: usize,
        cols: usize,
        i: usize,
        j: usize,
        q: &mut VecDeque<(usize, usize)>
    ) {
        if i >= rows || j >= cols || grid[i][j] != 1 {
            return;
        }

        grid[i][j] = -1;
        q.push_back((i, j));

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            Self::dfs_calc_first_island(grid, rows, cols, new_i, new_j, q);
        }
    }

    #[inline(always)]
    fn calc_first_island(
        grid: &mut Vec<Vec<i32>>,
        rows: &usize,
        cols: &usize,
    ) -> VecDeque<(usize, usize)> {
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..*rows {
            for j in 0..*cols {
                if grid[i][j] == 1 {
                    Self::dfs_calc_first_island(grid, *rows, *cols, i, j, &mut q);
                    return q;
                }
            }
        }

        unreachable!()
    }

    pub fn shortest_bridge(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut q = Self::calc_first_island(&mut grid, &rows, &cols);
        let mut count = 0_i32;

        while !q.is_empty() {
            let curr_len = q.len();

            for _ in 0..curr_len {  
                let (i, j) = q.pop_front().unwrap();

                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + dx) as usize;
                    let new_j = (j as isize + dy) as usize;

                    if new_i >= rows || new_j >= cols || grid[new_i][new_j] == -1 {
                        continue;
                    }

                    if grid[new_i][new_j] == 1 {
                        return count;
                    }

                    grid[new_i][new_j] = -1;
                    q.push_back((new_i, new_j));
                }
            }

            count += 1;
        }

        unreachable!()
    }
}
