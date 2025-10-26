impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {

        let mut left_idx = 0;
        let mut right_idx = height.len() - 1;
        let mut left_height = height[left_idx];
        let mut right_height = height[right_idx];
        let mut sum = 0_i32;

        while left_idx + 1 < right_idx {
            if left_height < right_height {
                left_idx += 1;
                let new_height = height[left_idx];

                if left_height > new_height {
                    sum += left_height - new_height;
                } else {
                    left_height = new_height;
                }

            } else {
                right_idx -= 1;
                let new_height = height[right_idx];

                if right_height > new_height {
                    sum += right_height - new_height;
                } else {
                    right_height = new_height;
                }
            }
        }

        sum
    }
}
