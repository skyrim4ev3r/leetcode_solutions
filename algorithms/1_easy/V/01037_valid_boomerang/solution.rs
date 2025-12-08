impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        let dx1 = points[1][0] - points[0][0];
        let dy1 = points[1][1] - points[0][1];

        let dx2 = points[2][0] - points[0][0];
        let dy2 = points[2][1] - points[0][1];

        if (dx1 == 0 && dx2 == 0) || (dx1 == 0 && dy1 == 0) || (dx2 == 0 && dy2 == 0) {
            return false;
        }

        dx1 == 0 || dx2 == 0 || (dy1 as f64 / dx1 as f64) != (dy2 as f64 / dx2 as f64)
    }
}
