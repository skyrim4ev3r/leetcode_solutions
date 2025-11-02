impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {

        let n_i64 = n as i64;
        let mut low = 1_i64;
        let mut high = n_i64;

        while low <= high {

            let mid = low + (high - low) / 2;
            let curr_sum = (mid * (mid + 1)) / 2;

            if curr_sum == n_i64 {
                return mid as i32;
            }

            if curr_sum < n_i64 {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low as i32 - 1
    }
}
