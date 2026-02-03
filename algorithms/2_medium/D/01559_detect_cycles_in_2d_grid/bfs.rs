use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut visited = vec![vec![false; cols]; rows];
        let mut q: VecDeque<(u16, u16)> = VecDeque::new();

        for i in 0..rows {
            for j in 0..cols {
                if !visited[i][j] {
                    let parent_char = grid[i][j];
                    visited[i][j] = true;
                    q.push_back((i as u16, j as u16));

                    while let Some((old_i, old_j)) = q.pop_front() {
                        let mut count = 0_u8;

                        for (dx, dy) in Self::DIRECTIONS.iter() {
                            let new_i = (old_i as isize + dx) as usize;
                            let new_j = (old_j as isize + dy) as usize;

                            if new_i >= rows || new_j >= cols || grid[new_i][new_j] != parent_char {
                                continue;
                            }

                            if visited[new_i][new_j] {
                                count += 1;

                                if count >= 2 {
                                    return true;
                                }

                                continue;
                            }

                            visited[new_i][new_j] = true;
                            q.push_back((new_i as u16, new_j as u16));
                        }
                    }
                }

            }
        }

        false
    }
}
