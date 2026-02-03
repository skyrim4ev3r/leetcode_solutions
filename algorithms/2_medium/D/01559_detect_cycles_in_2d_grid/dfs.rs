impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    fn dfs(
        grid: &Vec<Vec<char>>,
        visited: &mut Vec<Vec<bool>>,
        parent_char: char,
        i: usize,
        j: usize,
        rows: usize,
        cols: usize,
        has_cycle: &mut bool,
    ) -> bool {
        if *has_cycle || i >= rows || j >= cols || grid[i][j] != parent_char {
            return false;
        }

        if visited[i][j] {
            return true;
        }

        visited[i][j] = true;
        let mut count = 0_u8;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            if Self::dfs(grid, visited, parent_char, new_i, new_j, rows, cols, has_cycle) {
                count += 1;
            }

            if count >= 2 {
                *has_cycle = true;
                return false;
            }
        }

        false
    }

    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut visited = vec![vec![false; cols]; rows];
        let mut has_cycle = false;

        for i in 0..rows {
            for j in 0..cols {
                if !visited[i][j] {
                    let parent_char = grid[i][j];

                    Self::dfs(&grid, &mut visited, parent_char, i, j, rows, cols, &mut has_cycle);

                    if has_cycle {
                        return true;
                    }
                }

            }
        }

        false
    }
}
