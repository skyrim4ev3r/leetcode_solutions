impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        let len = colors.len();

        let mut right = len - 1;
        while right > 0 && colors[right] == colors[0] {
            right -= 1;
        }

        let mut left = 0_usize;
        while left < len - 1 && colors[left] == colors[len - 1] {
            left += 1;
        }

        std::cmp::max(right, len - 1 - left) as i32
    }
}
