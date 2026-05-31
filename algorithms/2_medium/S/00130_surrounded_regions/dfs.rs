impl Solution {
    const ATTACKER: char = 'X';
    const DEFENDER: char = 'O';
    const DEFENDER_MARKED: char = '+';
    const DIRECTIONS: [(isize, isize); 4] = [(0 , 1), (0, -1), (1, 0), (-1, 0)];

    fn dfs_mark_defender(board: &mut Vec<Vec<char>>, rows: isize, cols: isize, i: isize, j: isize) {
        if i < 0 || j < 0 || i >= rows || j >= cols || board[i as usize][j as usize] != Self::DEFENDER {
            return;
        }

        board[i as usize][j as usize] = Self::DEFENDER_MARKED;

        for &(dx, dy) in &Self::DIRECTIONS {
            Self::dfs_mark_defender(board, rows, cols, i + dx, j + dy);
        }
    }

    fn mark_defenders_at_edges(board: &mut Vec<Vec<char>>, rows: isize, cols: isize) {
        for i in 0..rows {
            Self::dfs_mark_defender(board, rows, cols, i, 0);
            Self::dfs_mark_defender(board, rows, cols, i, cols - 1);
        }

        for j in 0..cols {
            Self::dfs_mark_defender(board, rows, cols, 0, j);
            Self::dfs_mark_defender(board, rows, cols, rows - 1, j);
        }
    }

    pub fn solve(board: &mut Vec<Vec<char>>) {
        let rows = board.len() as isize;
        let cols = board[0].len() as isize;

        Self::mark_defenders_at_edges(board, rows, cols);

        for i in 0..rows {
            for j in 0..cols {
                if board[i as usize][j as usize] == Self::DEFENDER_MARKED {
                    board[i as usize][j as usize] = Self::DEFENDER;
                } else if board[i as usize][j as usize] == Self::DEFENDER {
                    board[i as usize][j as usize] = Self::ATTACKER;
                }
            }
        }
    }
}
