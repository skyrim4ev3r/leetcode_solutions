impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut right = height.len() - 1;
        let mut curr_max_left = 0_i32;
        let mut curr_max_right = 0_i32;
        let mut total = 0_i32;

        while left < right {
            if height[left] < height[right] {
                if curr_max_left > height[left] {
                    total += curr_max_left - height[left];
                } else {
                    curr_max_left = height[left];
                }
                left += 1;
            } else {
                if curr_max_right > height[right] {
                    total += curr_max_right - height[right];
                } else {
                    curr_max_right = height[right];
                }
                right -= 1;
            }
        }

        total
    }
}
