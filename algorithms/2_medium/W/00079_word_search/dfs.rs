impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs(
        board: &[Vec<char>],
        rows: usize,
        cols: usize,
        i: usize,
        j: usize,
        is_visited: &mut [Vec<bool>],
        word: &[u8],
        word_len: usize,
        word_idx: usize,
        is_find: &mut bool,
    ) {
        if *is_find { return; }

        if word_idx == word_len {
            *is_find = true;
            return;
        }

        if i >= rows || j >= cols || is_visited[i][j] || board[i][j] != word[word_idx] as char {
            return;
        }

        is_visited[i][j] = true;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;
            Self::dfs(board, rows, cols, new_i, new_j, is_visited, word, word_len, word_idx + 1, is_find);
        }

        is_visited[i][j] = false;
    }

    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let rows = board.len();
        let cols = board[0].len();
        let word_len = word.len();
        let word_idx = 0;
        let mut is_visited = vec![vec![false; cols]; rows];
        let mut is_find = false;

        for i in 0..rows {
            for j in 0..cols {
                Self::dfs(&board, rows, cols, i, j, &mut is_visited, word.as_bytes(), word_len, word_idx, &mut is_find);

                if is_find {
                    return true;
                }
            }
        }

        false
    }
}
