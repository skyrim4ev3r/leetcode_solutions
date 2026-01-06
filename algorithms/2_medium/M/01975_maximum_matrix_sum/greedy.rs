impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut count_negative = 0_i32;
        let mut sum = 0_i64;
        let mut min_abs_val = i32::MAX;

        for row in matrix.iter() {
            for &cell in row.iter() {
                if cell < 0 {
                    count_negative += 1;
                }

                min_abs_val = min_abs_val.min(cell.abs());
                sum += cell.abs() as i64;
            }
        }

        if (count_negative & 1) == 1 {
            // Adjust the total sum if there are an odd number of negative values.
            // If there is at least one zero in the matrix, then `min_abs_val` will be zero,
            // and subtracting twice `min_abs_val` will have no effect on the sum, 
            // effectively covering that edge case as well.
            sum -= (2 * min_abs_val) as i64;
        }

        sum
    }
}
