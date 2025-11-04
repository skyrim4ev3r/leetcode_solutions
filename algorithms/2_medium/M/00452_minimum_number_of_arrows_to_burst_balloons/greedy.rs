impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

        let len = points.len();
        let mut prev_end = points[0][1];
        let mut count = 1_i32;

        for i in 1..len {
            if points[i][0] > prev_end {
                prev_end = points[i][1];
                count += 1;
            }
        }

        count
    }
}
