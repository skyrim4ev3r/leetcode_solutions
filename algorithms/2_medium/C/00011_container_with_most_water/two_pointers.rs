impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut right = height.len() - 1;
        let mut max = 0_i32;

        while left < right {
            let height_l = height[left];
            let height_r = height[right];
            let curr_min_height = height_l.min(height_r);
            max = max.max((right - left) as i32 * curr_min_height);

            if height_l < height_r {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max
    }
}
