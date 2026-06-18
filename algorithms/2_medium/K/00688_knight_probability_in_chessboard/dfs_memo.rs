impl Solution {
    const DIRECTIONS: [(isize, isize); 8] = [
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
        (1, 2), (2, 1), (2, -1), (1, -2),
    ];

    fn dfs(n: isize, k: i32, row: isize, col: isize, cnt_move: i32, memo: &mut[f64]) -> f64 {
        if k == cnt_move {
            return 1_f64;
        }

        let memo_idx = cnt_move as isize * n * n + row * n + col;
        if memo[memo_idx as usize] != -1_f64 {
            return memo[memo_idx as usize];
        }
        let mut prob = 0_f64;
        let mut in_cnt = 0_i32;
 
        for (dx, dy) in Self::DIRECTIONS {
            let (new_row, new_col) = (row + dx, col + dy);
            if new_row >= 0 && new_col >= 0 && new_row < n && new_col < n {
                in_cnt += 1;
                prob += Self::dfs(n, k, new_row, new_col, cnt_move + 1, memo);
            }
        }

        let res = prob / Self::DIRECTIONS.len() as f64;
        memo[memo_idx as usize] = res;
        res
    }

    pub fn knight_probability(n: i32, k: i32, row: i32, col: i32) -> f64 {
        assert!(row >= 0 && col >= 0 && row < n && col < n && k >= 0);
        let (n, row, col) = (n as isize, row as isize, col as isize);
        let mut memo = vec![-1_f64; (n * n * k as isize) as usize];

        Self::dfs(n, k, row, col, 0, &mut memo)
    }
}
