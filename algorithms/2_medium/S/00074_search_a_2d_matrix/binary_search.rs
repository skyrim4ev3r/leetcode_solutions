impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let row =  matrix.partition_point(|row| row[0] <= target) - 1;
        row < matrix.len() && matrix[row].binary_search(&target).is_ok()
    }
}
