impl Solution {
    pub fn find_degrees(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        matrix
            .iter()
            .map(|m| m.iter().sum::<i32>())
            .collect::<Vec<_>>()
    }
}
