use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    pub fn highest_peak(mut is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = is_water.len();
        let cols = is_water[0].len();
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();
        let mut curr_height = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if is_water[i][j] == 1 {
                    queue.push_back((i, j));
                }

                is_water[i][j] -= 1;
            }
        }

        while !queue.is_empty() {
            let curr_len = queue.len();
            curr_height += 1;

            for _ in 0..curr_len {
                let (i, j) = queue.pop_front().unwrap();

                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + dx) as usize;
                    let new_j = (j as isize + dy) as usize;

                    if new_i >= rows || new_j >= cols || is_water[new_i][new_j] != -1 {
                        continue;
                    }

                    is_water[new_i][new_j] = curr_height;

                    queue.push_back((new_i, new_j));
                }

            }
        }

        is_water
    }
}
