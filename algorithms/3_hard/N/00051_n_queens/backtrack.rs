impl Solution {

    #[inline] 
    fn is_safe(board: &Vec<Vec<u8>>, len: &usize, i: &usize, j: &usize) -> bool {

        for ofs in 0..=*i {
            if board[*i - ofs][*j] == b'Q' {
                return false;
            }

            if *j >= ofs && board[*i - ofs][*j - ofs] == b'Q' {
                return false;
            }

            if (*j + ofs) < *len && board[*i - ofs][*j + ofs] == b'Q' {
                return false;
            }
        }

        true
    }

    fn backtrack(res: &mut Vec<Vec<String>>, board: &mut Vec<Vec<u8>>, len: usize, curr_row: usize) {
        if curr_row == len {
            let mut curr_board_as_string: Vec<String> = Vec::with_capacity(len);

            for row in board.iter() {
               curr_board_as_string.push(String::from_utf8_lossy(row).into_owned());
            }

            res.push(curr_board_as_string);
            return;
        }

        for col in 0..len {
            if Self::is_safe(board, &len, &curr_row, &col) {
                board[curr_row][col] = b'Q';
                Self::backtrack(res, board, len, curr_row + 1);
                board[curr_row][col] = b'.';
            }
        }
    }

    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {

        let len = n as usize;
        let mut res: Vec<Vec<String>> = Vec::new(); 
        let mut board = vec![vec![b'.'; len]; len];

        Self::backtrack(&mut res, &mut board, len, 0_usize);

        res
    }
}
