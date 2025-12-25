use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = mat.len();
        let cols = mat[0].len();

        let mut res = vec![vec![0_i32; cols]; rows];
        let mut is_visited = vec![vec![false; cols]; rows];
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..rows {
            for j in 0..cols {
                if mat[i][j] == 0 {
                    q.push_back((i, j));
                    is_visited[i][j] = true;
                }
            }
        }

        let mut curr_level = 0_i32;

        while !q.is_empty() {
            let curr_len = q.len();

            for _ in 0..curr_len {
                let (i, j) = q.pop_front().unwrap();
                res[i][j] = curr_level;

                for (dx, dy) in Self::DIRECTIONS.iter() {
                    let new_i = (i as isize + dx) as usize;
                    let new_j = (j as isize + dy) as usize;

                    if new_i >= rows || new_j >= cols || is_visited[new_i][new_j] {
                        continue;
                    }

                    is_visited[new_i][new_j] = true;
                    q.push_back((new_i, new_j));
                }
            }

            curr_level += 1;
        }

        res
    }
}
