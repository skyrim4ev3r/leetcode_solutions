impl Solution {
    pub fn all_cells_dist_order(rows: i32, cols: i32, r_center: i32, c_center: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::with_capacity((rows as usize) * (cols as usize));

        for i in 0..rows {
            for j in 0..cols {
                res.push(vec![i , j]);
            }
        }

        res.sort_unstable_by(|a, b| {
            let da = (a[0] - r_center).abs() + (a[1] - c_center).abs();
            let db = (b[0] - r_center).abs() + (b[1] - c_center).abs();

            da.cmp(&db)
        });

        res
    }
}
