impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(-1, 0), (0, -1), (1, 0), (0, 1)];
    const MOD_TO: i32 = 1_000_000_007;

    fn backtrack(
        i: usize,
        j: usize,
        move_left: usize,
        rows: usize,
        cols: usize,
        dp: &mut Vec<Vec<Vec<i32>>>,
    ) -> i32 {
        if i >= rows || j >= cols {
            return 1;
        }

        if move_left == 0 {
            return 0;
        }

        if dp[i][j][move_left] != -1 {
            return dp[i][j][move_left];
        }

        let mut sum = 0_i32;

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            sum = (sum + Self::backtrack(new_i, new_j, move_left - 1, rows, cols, dp)) % Self::MOD_TO;
        }

        dp[i][j][move_left] = sum;
        sum
    }

    pub fn find_paths(m: i32, n: i32, max_move: i32, start_row: i32, start_column: i32) -> i32 {
        let (rows, cols, move_left) = (m as usize, n as usize, max_move as usize);
        let (i_start, j_start) =  (start_row as usize, start_column as usize);
        let mut dp = vec![vec![vec![-1_i32; move_left + 1]; cols]; rows];

        Self::backtrack(i_start, j_start, move_left, rows, cols, &mut dp)
    }
}
