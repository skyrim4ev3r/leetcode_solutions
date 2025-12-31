impl Solution {
    #[inline]
    fn check_sub_mat(grid: &Vec<Vec<i32>>, i_st: usize, j_st: usize) -> bool {
        let mut seen = [false; 10];

        for i in i_st..(i_st + 3) {
            for j in j_st..(j_st + 3) {
                let val = grid[i][j];

                if val < 1 || val > 9 {
                    return false;
                }

                if seen[val as usize] {
                    return false;
                }

                seen[val as usize] = true;
            }
        }

        let sum = grid[i_st][j_st] + grid[i_st + 1][j_st] + grid[i_st + 2][j_st];

        for i in i_st..(i_st + 3) {
            if grid[i][j_st] + grid[i][j_st + 1] + grid[i][j_st + 2] != sum {
                return false;
            }
        }

        for j in (j_st + 1)..(j_st + 3) {
            if grid[i_st][j] + grid[i_st + 1][j] + grid[i_st + 2][j] != sum {
                return false;
            }
        }

        if (
            grid[i_st][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st + 2][j_st + 2] != sum ||
            grid[i_st + 2][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st][j_st + 2] != sum
        ) {
            return false;
        }

        true
    }

    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut count = 0_i32;

        if rows < 3 || cols < 3 {
            return 0;
        }

        for i in 0..(rows - 2) {
            for j in 0..(cols - 2) {
                if Self::check_sub_mat(&grid, i, j) {
                    count += 1;
                }
            }
        }

        count
    }
}
