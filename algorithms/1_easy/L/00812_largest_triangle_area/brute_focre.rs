impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let mut max = 0.0_f64;
        let len = points.len();

        for i in 0..(len - 2) {
            for j in (i + 1)..(len - 1) {
                for k in (j + 1)..len {
                    // Calculate the area of the triangle using the determinant method
                    // Area = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
                    let area = (points[i][0] * ( points[j][1] - points[k][1])
                                + points[j][0] * ( points[k][1] - points[i][1])
                                + points[k][0] * ( points[i][1] - points[j][1])
                                ).abs() as f64 /2.0_f64;

                    max = max.max(area);
                }
            }
        }

        max
    }
}
