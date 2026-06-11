impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];

    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        debug_assert!(board.len() > 0 && board[0].len() > 0);
        let rows = board.len() as isize;
        let cols = board[0].len() as isize;
        let mut life_state = vec![false; (rows * cols) as usize];

        for i in 0..rows {
            for j in 0..cols {
                let mut count = 0;

                for (dx, dy) in Self::DIRECTIONS {
                    let ni = i + dx;
                    let nj = j + dy;

                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni as usize][nj as usize] == 1 {
                        count += 1;
                    }
                }

                let idx_life_state = ((i * cols) + j) as usize;
                if count > 3 {
                    life_state[idx_life_state] = false;
                } else if count == 3 {
                    life_state[idx_life_state] = true;
                } else if count == 2 {
                    if board[i as usize][j as usize] == 1 {
                        life_state[idx_life_state] = true;
                    } else {
                        life_state[idx_life_state] = false;
                    }
                } else {
                    life_state[idx_life_state] = false;
                }
            }
        }

        for i in 0..(rows as usize) {
            for j in 0..(cols as usize) {
                let idx_life_state = (i * cols as usize) + j;
                if life_state[idx_life_state] {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
}
