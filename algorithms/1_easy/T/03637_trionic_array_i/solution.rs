impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let len = nums.len();

        if len <= 3 || nums[0] >= nums[1] || nums[len - 2] >= nums[len - 1] {
            return false;
        }

        let mut change_count = 0_i32;
        let mut is_increasing = true;

        for i in 1..len {
            if change_count > 2 || nums[i] == nums[i - 1] {
                return false;
            }

            if (nums[i] > nums[i - 1]) != is_increasing {
                is_increasing = !is_increasing;
                change_count += 1;
            }
        }

        change_count == 2
    }
}
