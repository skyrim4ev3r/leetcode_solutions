impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let rows = m as usize;
        let cols = n as usize;

        let mut grid = vec![vec![b'.'; cols]; rows];

        for guard in guards.into_iter() {
            grid[guard[0] as usize][guard[1] as usize] = b'g';
        }

        for wall in walls.into_iter() {
            grid[wall[0] as usize][wall[1] as usize] = b'w';
        }

        let mut is_covered = false;

        for j in 0..cols {
            is_covered = false;
            for i in 0..rows {
                if grid[i][j] == b'g' {
                    is_covered = true;
                } else if grid[i][j] == b'w' {
                    is_covered = false;
                } else if is_covered {
                    grid[i][j] = b'c';
                }
            }

            is_covered = false;
            for i in (0..rows).rev() {
                if (grid[i][j] == b'g') {
                    is_covered = true;
                } else if grid[i][j] == b'w' {
                    is_covered = false;
                } else if is_covered {
                    grid[i][j] = b'c';
                }
            }
        }

        for i in 0..rows {
            is_covered = false;
            for j in 0..cols {
                if grid[i][j] == b'g' {
                    is_covered = true;
                } else if grid[i][j] == b'w' {
                    is_covered = false;
                } else if is_covered {
                    grid[i][j] = b'c';
                }
            }

            is_covered = false;
            for j in (0..cols).rev() {
                if grid[i][j] == b'g' {
                    is_covered = true;
                } else if grid[i][j] == b'w' {
                    is_covered = false;
                } else if is_covered {
                    grid[i][j] = b'c';
                }
            }
        }

        let mut count = 0_i32;
        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == b'.' {
                    count += 1;
                }
            }
        }

        count
    }
}
