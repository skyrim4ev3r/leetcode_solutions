impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let n = 8_usize;

        for i in 0..n {
            for j in 0..n {
                if board[i][j] == 'R' {
                    let mut count = 0_i32;

                    for (dx, dy) in Self::DIRECTIONS.iter() {
                        let mut new_i = (i as isize + dx) as usize;
                        let mut new_j = (j as isize + dy) as usize;

                        while new_i < n && new_j < n && board[new_i][new_j] == '.' {
                            new_i = (new_i as isize + dx) as usize;
                            new_j = (new_j as isize + dy) as usize;
                        }

                        if new_i < n && new_j < n && board[new_i][new_j] == 'p' {
                            count += 1;
                        }
                    }

                    return count;
                }
            }
        }

        -1
    }
}
