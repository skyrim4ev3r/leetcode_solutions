impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {

        let x = n as i64 * 2;
        let mut y = (x as f64).sqrt() as i64;

        if (y * (y + 1) > x) {
            y -= 1;
        }

        y as i32
    }
}
