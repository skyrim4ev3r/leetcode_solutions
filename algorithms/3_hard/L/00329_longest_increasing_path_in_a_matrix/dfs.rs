impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    fn dfs(
        matrix: &Vec<Vec<i32>>,
        dp: &mut Vec<Vec<i32>>,
        i: usize,
        j: usize,
        rows: usize,
        cols: usize,
    ) -> i32 {
        let cache = dp[i][j];
        if cache != -1 {
            return cache;
        }

        let mut longest = 1;
        let curr_cell = matrix[i][j];

        for (dx, dy) in Self::DIRECTIONS.iter() {
            let new_i = (i as isize + dx) as usize;
            let new_j = (j as isize + dy) as usize;

            if new_i >= rows || new_j >= cols || matrix[new_i][new_j] >= curr_cell {
                continue;
            }

            longest = longest.max(1 + Self::dfs(matrix, dp, new_i, new_j, rows, cols));
        }

        dp[i][j] = longest;
        longest
    }

    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut dp = vec![vec![-1_i32; cols]; rows];
        let mut max = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                max = max.max(Self::dfs(&matrix, &mut dp, i, j, rows, cols));
            }
        }

        max
    }
}
