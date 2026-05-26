impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut high = x as i64;
        let mut low = 0_i64;

        while low <= high {
            let mid = low + (high - low) / 2;

            if mid.pow(2) <= x as i64 {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        high as i32
    }
}
