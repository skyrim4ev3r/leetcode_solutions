struct NumMatrix {
    prefix: Vec<i32>,
    rows: usize,
    cols: usize,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {
    const MAX_ACCEPTED_ROWS: usize = 200;
    const MAX_ACCEPTED_COLS: usize = 200;

    fn new(matrix: Vec<Vec<i32>>) -> Self {
        debug_assert!(matrix.len() > 0 && matrix[0].len() > 0 &&
                      matrix.len() <= Self::MAX_ACCEPTED_ROWS && 
                      matrix[0].len() <= Self::MAX_ACCEPTED_COLS);
        let rows = matrix.len() + 1;
        let cols = matrix[0].len() + 1;
        let mut prefix = vec![0_i32; rows * cols];

        for i in 1..rows {
            debug_assert!(matrix[i - 1].len() + 1 == cols);
            for j in 1..cols {
                let prefix_idx = (i * cols + j);
                let prefix_idx_up = (i - 1) * cols + j;
                let prefix_idx_left = i * cols + j - 1;
                let prefix_idx_upleft = (i - 1) * cols + j - 1;

                prefix[prefix_idx] = matrix[i - 1][j - 1] + 
                                    prefix[prefix_idx_up] +
                                    prefix[prefix_idx_left] -
                                    prefix[prefix_idx_upleft];
            }
        }

        Self {
            prefix,
            rows,
            cols
        }
    }
    
    fn sum_region(&self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        debug_assert!(row1 >= 0 && col1 >= 0 && row2 >=0 && col2 >= 0 &&
                      row1 <= row2 && col1 <= col2 &&
                      row2 as usize + 1 < self.rows && col2 as usize + 1 < self.cols);

        let upleft = row1 as usize * self.cols + col1 as usize;
        let up = row1 as usize * self.cols + (col2 as usize + 1);
        let left = (row2 as usize + 1) * self.cols + col1 as usize;
        let downright = (row2 as usize + 1) * self.cols + (col2 as usize + 1);

        self.prefix[downright] + self.prefix[upleft] - self.prefix[up] - self.prefix[left]
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix::new(matrix);
 * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
 */
