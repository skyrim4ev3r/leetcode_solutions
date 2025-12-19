impl Solution {
    pub fn compute_area(ax1: i32, ay1: i32, ax2: i32, ay2: i32, bx1: i32, by1: i32, bx2: i32, by2: i32) -> i32 {
        let area1 = (ax2 - ax1) * (ay2 - ay1);
        let area2 = (bx2 - bx1) * (by2 - by1);

        let max_x1 = ax1.max(bx1);
        let max_y1 = ay1.max(by1);

        let min_x2 = ax2.min(bx2);
        let min_y2 = ay2.min(by2);

        if min_x2 > max_x1 && min_y2 > max_y1 {
            let shared_area = (min_y2 - max_y1) * (min_x2 - max_x1);
            return area1 + area2 - shared_area;
        }

        area1 + area2
    }
}
