impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

    fn dfs(
        matrix: &[Vec<i32>],
        dp: &mut [i32],
        i: isize,
        j: isize,
        rows: isize,
        cols: isize,
    ) -> i32 {
        if dp[(i * cols + j) as usize] != -1 {
            return dp[(i * cols + j) as usize];
        }

        let cell_val = matrix[i as usize][j as usize];
        let mut curr = 1_i32;

        for (dx, dy) in Self::DIRECTIONS {
            let ni = i + dx;
            let nj = j + dy;

            if ni < 0 || nj < 0 || ni >= rows || nj >= cols ||
               matrix[ni as usize][nj as usize ] <= cell_val {
                continue;
            }

            curr = curr.max(1 + Self::dfs(matrix, dp, ni, nj, rows, cols));
        }

        dp[(i * cols + j) as usize] = curr;
        curr
    }

    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        debug_assert!(matrix.len() > 0 && matrix[0].len() > 0);
        let rows = matrix.len() as isize;
        let cols = matrix[0].len() as isize;
        let mut dp = vec![-1_i32; (cols * rows) as usize];
        let mut max = 0_i32;

        for i in 0..rows {
            debug_assert!((matrix[i as usize].len() as isize) == cols);
            for j in 0..cols {
                max = max.max(Self::dfs(&matrix, &mut dp, i, j, rows, cols));
            }
        }

        max
    }
}
