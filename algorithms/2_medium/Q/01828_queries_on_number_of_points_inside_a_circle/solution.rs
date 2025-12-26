impl Solution {
    pub fn count_points(points: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut res = Vec::with_capacity(queries.len());

        for query in queries.iter() {
            let query_square = query[2] * query[2];
            let mut count = 0_i32;

            for point in points.iter() {
                let delta_x = query[0] - point[0];
                let delta_y = query[1] - point[1];
                let dis_square = delta_x * delta_x + delta_y * delta_y;

                if dis_square <= query_square {
                    count += 1;
                }
            }

            res.push(count);
        }

        res
    }
}
