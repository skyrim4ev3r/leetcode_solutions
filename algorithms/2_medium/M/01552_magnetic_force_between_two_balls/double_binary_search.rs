impl Solution {
    #[inline]
    fn check_mid(position: &Vec<i32>, mid: i32, m: i32, len: usize) -> bool {
        let mut curr_pos = 0_usize;
        let mut curr = position[curr_pos];
         
        for _ in 0..(m - 1) {
            let next = curr + mid;
            let next_pos = position[curr_pos + 1..].binary_search(&next).unwrap_or_else(|x| x) + curr_pos + 1;

            if next_pos == len {
                return false;
            }

            curr_pos = next_pos;
            curr = position[curr_pos];
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
