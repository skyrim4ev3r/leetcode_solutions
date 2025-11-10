impl Solution {
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {

        let len = coordinates.len();
        let first_dy = coordinates[1][1] - coordinates[0][1];
        let first_dx = coordinates[1][0] - coordinates[0][0];

        for i in 2..len {
            let curr_dy = coordinates[i][1] - coordinates[0][1];
            let curr_dx = coordinates[i][0] - coordinates[0][0];

            if first_dy * curr_dx != first_dx * curr_dy {
                return false;
            }
        }

        true
    }
}
