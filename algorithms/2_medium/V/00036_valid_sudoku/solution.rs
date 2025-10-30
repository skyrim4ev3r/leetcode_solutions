impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {

        // Check all rows are valid
        for i in 0..9 {
            let mut is_seen = [false; 9];
            for j in 0..9 {
                if board[i][j] != '.' {
                    let is_seen_index = (board[i][j] as u8 - b'1') as usize;
                    if is_seen[is_seen_index] {
                        return false;
                    }
                    is_seen[is_seen_index] = true;
                }
            }
        }

        // Check all cols are valid
        for j in 0..9 {
            let mut is_seen = [false; 9];
            for i in 0..9 {
                if board[i][j] != '.' {
                    let is_seen_index = (board[i][j] as u8 - b'1') as usize;
                    if is_seen[is_seen_index] {
                        return false;
                    }
                    is_seen[is_seen_index] = true;
                }
            }
        }

       // Check all 3*3 sub-boxes
        for cell in 0..9 {

            let mut is_seen = [false; 9];
            let start_i = (cell / 3) * 3;
            let start_j = (cell % 3) * 3;

            for i in start_i..(start_i + 3) {
                for j in start_j..(start_j + 3) {
                    if board[i][j] != '.' {
                        let is_seen_index = (board[i][j] as u8 - b'1') as usize;
                        if is_seen[is_seen_index] {
                            return false;
                        }
                        is_seen[is_seen_index] = true;
                    }
                }
            }
        }

        true
    }
}
