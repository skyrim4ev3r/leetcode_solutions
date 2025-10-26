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

    fn backtrack(count: &mut i32, board: &mut Vec<Vec<u8>>, len: usize, curr_row: usize) {
        if curr_row == len {
            *count += 1;
            return;
        }

        for col in 0..len {
            if Self::is_safe(board, &len, &curr_row, &col) {
                board[curr_row][col] = b'Q';
                Self::backtrack(count, board, len, curr_row + 1);
                board[curr_row][col] = b'.';
            }
        }
    }

    pub fn total_n_queens(n: i32) -> i32 {
        // Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed

        /*
        
        if 1 <= n && n <= 9 {
            return [1, 0, 0, 2, 10, 4, 40, 92, 352][n as usize - 1];
        }
        
        */
        
        // Backtracking solution

        let len = n as usize;
        let mut count = 0_i32; 
        let mut board = vec![vec![b'.'; len]; len];

        Self::backtrack(&mut count, &mut board, len, 0_usize);

        count
    }
}
