impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let len = nums.len();
        let mut right = 0_usize;
        let mut left = 0_usize;

        while right + 1 < len {
            let mut new_right = 0_usize;

            while left <= right {
                new_right = new_right.max(left + nums[left] as usize);
                left += 1;
            }

            if new_right <= right {
                return false;
            }

            right = new_right;
        }

        true
    }
}
