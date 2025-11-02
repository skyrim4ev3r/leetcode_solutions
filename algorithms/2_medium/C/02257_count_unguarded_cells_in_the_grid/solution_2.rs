impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let rows = m as usize;
        let cols = n as usize;

        let mut grid = vec![vec![b'.'; cols]; rows];

        for guard in guards.iter() {
            grid[guard[0] as usize][guard[1] as usize] = b'g';
        }

        for wall in walls.into_iter() {
            grid[wall[0] as usize][wall[1] as usize] = b'w';
        }

        for guard in guards.into_iter() {
            let x = guard[0] as usize;
            let y = guard[1] as usize;

            for i in (0..x).rev() {
                if grid[i][y] == b'g' || grid[i][y] == b'w' {
                    break;
                }

                grid[i][y] = b'c';
            }

            for i in (x + 1)..rows {
                if grid[i][y] == b'g' || grid[i][y] == b'w' {
                    break;
                }

                grid[i][y] = b'c';
            }

            for j in (0..y).rev() {
                if grid[x][j] == b'g' || grid[x][j] == b'w' {
                    break;
                }

                grid[x][j] = b'c';
            }

            for j in (y + 1)..cols {
                if grid[x][j] == b'g' || grid[x][j] == b'w' {
                    break;
                }

                grid[x][j] = b'c';
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
