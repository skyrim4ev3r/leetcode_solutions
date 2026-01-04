impl Solution {
    pub fn min_moves_to_capture_the_queen(a: i32, b: i32, c: i32, d: i32, e: i32, f: i32) -> i32 {
        if a == e {
            if c == a && d > b.min(f) && d < b.max(f) {
                return 2;
            }

            return 1;
        }

        if b == f {
            if b == d && c > a.min(e) && c < a.max(e) {
                return 2;
            }

            return 1;
        }

        if (e - c).abs() == (f - d).abs() {
            if (a - c).abs() == (b - d).abs() {
                if a > c.min(e) && a < c.max(e) && b > d.min(f) && b < d.max(f) {
                    return 2;
                }
            }

            return 1;
        }

        2
    }
}
