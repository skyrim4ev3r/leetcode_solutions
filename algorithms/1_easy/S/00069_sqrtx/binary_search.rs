impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {

        let x_i64 = x as i64;
        let mut high = x_i64;
        let mut low = 1_i64;

        while low <= high {

            let mid = low + (high - low) / 2;
            let square_mid = mid * mid;

            if square_mid == x_i64 {
                return mid as i32;
            }

            if square_mid < x_i64 {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low as i32 - 1
    }
}
