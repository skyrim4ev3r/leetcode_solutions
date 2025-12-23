impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        for row in matrix.iter() {
            if let Ok(_) = row.binary_search(&target) {
                return true;
            }
        }

        false
    }
}
