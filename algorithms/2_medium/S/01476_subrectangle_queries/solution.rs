struct SubrectangleQueries {
    rectangle: Vec<Vec<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SubrectangleQueries {

    fn new(rectangle: Vec<Vec<i32>>) -> Self {
        Self {
            rectangle,
        }
    }

    fn update_subrectangle(&mut self, row1: i32, col1: i32, row2: i32, col2: i32, new_value: i32) {
        let row1_usize = row1 as usize;
        let row2_usize = row2 as usize;
        let col1_usize = col1 as usize;
        let col2_usize = col2 as usize;

        for i in row1_usize..=row2_usize {
            for j in col1_usize..=col2_usize {
                self.rectangle[i][j] = new_value;
            }
        } 
    }

    fn get_value(&self, row: i32, col: i32) -> i32 {
        self.rectangle[row as usize][col as usize]
    }
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * let obj = SubrectangleQueries::new(rectangle);
 * obj.update_subrectangle(row1, col1, row2, col2, newValue);
 * let ret_2: i32 = obj.get_value(row, col);
 */
