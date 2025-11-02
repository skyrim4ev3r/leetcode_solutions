impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {

        let num_i64 = num as i64;
        let mut high = num_i64;
        let mut low = 1_i64;

        while low <= high {

            let mid = low + (high - low) / 2;
            let square_mid = mid * mid;

            if square_mid == num_i64 {
                return true;
            }

            if square_mid < num_i64 {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        false
    }
}
