impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        points.sort_unstable_by(|a, b| {
            (a[0] * a[0] + a[1] * a[1]).cmp( &(b[0] * b[0] + b[1] * b[1]))
        });

        points.resize(k as usize, Vec::new());

        points
    }
}
