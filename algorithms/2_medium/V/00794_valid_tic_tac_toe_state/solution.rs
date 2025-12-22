impl Solution {
    #[inline]
    fn check_win(b: &Vec<&[u8]>, n: usize, player: u8) -> bool {
        for i in 0..n {
            let mut is_winning = true;

            for j in 0..n {
                if b[i][j] != player {
                    is_winning = false;
                    break;
                }
            }

            if is_winning {
                return true;
            }
        }

        for j in 0..n {
            let mut is_winning = true;

            for i in 0..n {
                if b[i][j] != player {
                    is_winning = false;
                    break;
                }
            }

            if is_winning {
                return true;
            }
        }

        let mut is_winning = true;;
        for i in 0..n {
            if b[i][i] != player {
                is_winning = false;
                break;
            }
        }

        if is_winning {
            return true;
        }

        for i in 0..n {
            if (b[i][n - 1 - i] != player) {
                return false;
            }
        }

        return true;
    }
    pub fn valid_tic_tac_toe(board: Vec<String>) -> bool {
        let n = board.len();
        let board_bytes = board.iter().map(|x| x.as_bytes()).collect::<Vec<_>>();
        let mut balance = 0_i32;

        for i in 0..n {
            for j in 0..n {
                if board_bytes[i][j] == b'X' {
                    balance += 1;
                } else if board_bytes[i][j] == b'O' {
                    balance -= 1;
                }
            }
        }

        if balance > 1 || balance < 0 {
            return false;
        };

        let is_player1_winner = Self::check_win(&board_bytes, n, b'X');
        let is_player2_winner = Self::check_win(&board_bytes, n, b'O');

        if (
            (is_player1_winner && is_player2_winner) || 
            (is_player1_winner && balance == 0) ||
            (is_player2_winner && balance == 1)
        ) {
            return false;
        }

        true
    }
}
