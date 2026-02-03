impl Solution {
    #[inline]
    fn check_mid(position: &Vec<i32>, mid: i32, m: i32, len: usize) -> bool {
        let mut pos = 0_usize;
         
        for _ in 0..(m - 1) {
            let next_val = position[pos] + mid;

            while pos < len && position[pos] < next_val {
                pos += 1;
            }

            if pos == len {
                return false;
            }
        }

        true
    }

    pub fn max_distance(mut position: Vec<i32>, m: i32) -> i32 {
        position.sort_unstable();
        let len = position.len();
        let mut left = 1_i32;
        let mut right = (position[len - 1] - position[0]) / (m - 1);

        while left <= right {
            let mid = left + (right - left) / 2;

            if Self::check_mid(&position, mid, m, len) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left - 1
    }
}
