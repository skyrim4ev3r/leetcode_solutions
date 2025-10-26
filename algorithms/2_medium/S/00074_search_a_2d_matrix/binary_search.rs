impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        for row in matrix.into_iter() {
            let pos = row.binary_search(&target);
            match pos {
                Ok(_) => return true,
                _ => {}
            };
        }

        false
    }
}
