impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let len = nums.len();

        if len <= 3 || nums[0] >= nums[1] || nums[len - 2] >= nums[len - 1] {
            return false;
        }

        let mut change_count = 0_i32;
        let mut is_increasing = true;

        for window in nums.windows(2) {
            if change_count > 2 || window[1] == window[0] {
                return false;
            }

            if (window[1] > window[0]) != is_increasing {
                is_increasing = !is_increasing;
                change_count += 1;
            }
        }

        change_count == 2
    }
}
