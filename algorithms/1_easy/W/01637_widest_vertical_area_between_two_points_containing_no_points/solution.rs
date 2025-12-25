impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable_by(|a, b| a[0].cmp(&b[0]));

        let mut max = 0_i32;
        let len = points.len();

        for w in points.windows(2) {
            max = max.max(w[1][0] - w[0][0]);
        }

        max
    }
}
