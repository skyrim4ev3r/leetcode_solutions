impl Solution {
    pub fn rotate_the_box(mut box_grid: Vec<Vec<char>>) -> Vec<Vec<char>> {

        let original_rows = box_grid.len();
        let original_cols = box_grid[0].len();

        let rows = original_cols;
        let cols = original_rows;

        let mut res: Vec<Vec<char>> = vec![vec!['.'; cols]; rows];
        for i in 0..rows {
            for j in 0..cols {
                res[i][j] = box_grid[cols - j - 1][i];
            }
        }

        for j in 0..cols {

            let mut top = 0;
            let mut bottom = 0;

            while bottom < rows {

                let mut leaf_count = 0_usize;
                while bottom < rows && res[bottom][j] != '*' {
                    if res[bottom][j] == '#' {
                        leaf_count += 1;
                        res[bottom][j] = '.';
                    }
                    bottom += 1;
                }

                for i in (bottom - leaf_count)..bottom {
                    res[i][j] = '#';
                }

                bottom = bottom + 1;
                top = bottom;
            }
        }

        res
    }
}
