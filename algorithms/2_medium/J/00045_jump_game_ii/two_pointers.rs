impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut left = 0_usize;
        let mut right = 0_usize;
        let mut steps = 0_i32;

        while right < len - 1 {
            let mut new_right = 0_usize;
            while left <= right {
                new_right = new_right.max(left + nums[left] as usize);
                left += 1;
            }
            // If new_right <= right there is no progress — indicates invalid input.
            right = new_right;
            steps += 1;
        }

        steps
    }
}
