impl Solution {
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {

        let mut row_vals = vec![0_i32; m as usize];
        let mut col_vals = vec![0_i32; n as usize];

        for index in indices.into_iter() {
            row_vals[index[0] as usize] += 1;
            col_vals[index[1] as usize] += 1;
        }

        let mut count = 0_i32;

        for row_val in row_vals.into_iter() {
            for &col_val in col_vals.iter() {
                if ((row_val + col_val) & 1) == 1 {
                    count += 1;
                }
            }
        }

        count
    }
}
