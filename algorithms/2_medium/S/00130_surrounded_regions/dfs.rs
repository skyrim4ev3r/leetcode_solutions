impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0 , 1), (0, -1), (1, 0), (-1, 0)];

    fn dfs(board: &mut Vec<Vec<char>>, m: usize, n: usize, i: usize, j: usize) {
        if i >= m || j >= n || board[i][j] != 'O' {
            return;
        }

        board[i][j] = 'W';

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            Self::dfs(board, m, n, new_i, new_j);
        }
    }

    pub fn solve(board: &mut Vec<Vec<char>>) {
        let m = board.len();
        let n = board[0].len();

        for j in 0..n {
            Self::dfs(board, m, n, 0, j);
            Self::dfs(board, m, n, m - 1, j);
        }

        for i in 0..m {
            Self::dfs(board, m, n, i, 0);
            Self::dfs(board, m, n, i, n - 1);
        }

        for i in 0..m {
            for j in 0..n {
                if board[i][j] == 'W' {
                    board[i][j] = 'O';
                } else if board[i][j] == 'O' {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
