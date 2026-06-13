impl Solution {
    pub fn is_perfect_square(num_i32: i32) -> bool {
        debug_assert!(num_i32 > 0);
        let num = num_i32;
        let mut hi = num;
        let mut lo = 1;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            let square_mid = mid * mid;

            if square_mid == num {
                return true;
            }

            if square_mid < num {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        false
    }
}
