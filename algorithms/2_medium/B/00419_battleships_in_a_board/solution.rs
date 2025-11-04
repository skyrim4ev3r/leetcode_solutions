impl Solution {
    pub fn count_battleships(board: Vec<Vec<char>>) -> i32 {
        let rows = board.len();
        let cols = board[0].len();
        let mut count = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if board[i][j] == 'X' {
                    if (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }

                    count += 1;
                }
            }
        }

        count
    }
}
