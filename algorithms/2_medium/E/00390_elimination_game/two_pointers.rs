impl Solution {
    pub fn last_remaining(n: i32) -> i32 {
        debug_assert!(n >= 1);
        let mut hi = n;
        let mut lo = 1_i32;
        let mut steps = 1_i32;
        let mut lo_to_hi = true;

        while lo < hi {
            let cnt = ((hi - lo + 1) + (steps - 1)) / steps;

            if lo_to_hi {
                lo += steps;
                if (cnt & 1) == 1 {
                    hi -= steps;
                }
            } else {
                hi -= steps;
                if (cnt & 1) == 1 {
                    lo += steps;
                }
            }

            steps *= 2;
            lo_to_hi = !lo_to_hi;
        }

        lo
    }
}
