impl Solution {
    pub fn ones_minus_zeros(mut grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {

        let rows = grid.len();
        let cols = grid[0].len();

        /*
            diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
                       = onesRowi + onesColj - (len_row - onesRowi) - (len_cols - onesColj)
                       = onesRowi + onesColj - len_row + onesRowi - len_cols + onesColj

                       = 2 * onesRowi + 2 * onesColj - (len_cols + len_row)
        */

        // creating a variable to avoid convert in each iteration for this part => (len_cols + len_row)
        let sum_rows_cols = (rows + cols) as i32;

        let mut ones_rows_mul_by_2 = vec![0_i32; rows];
        let mut ones_cols_mul_by_2 = vec![0_i32; cols];

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    ones_rows_mul_by_2[i] += 2; // Increment by 2 to use it instead of => 2 * onesRowi 
                    ones_cols_mul_by_2[j] += 2; // Increment by 2 to use it instead of => 2 * ones_cols 
                }
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                // 2 * onesRowi + 2 * onesColj - (len_cols + len_row)
                grid[i][j] = ones_rows_mul_by_2[i] + ones_cols_mul_by_2[j] - sum_rows_cols;
            }
        }

        grid
    }
}
