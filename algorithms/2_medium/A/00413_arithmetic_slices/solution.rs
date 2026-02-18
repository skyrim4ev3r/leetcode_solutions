impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut prev_diff = 0_i32;
        let mut curr_len = 0_i32;
        let mut count = 0_i32;

        for i in 1..len {
            if nums[i] - nums[i - 1] == prev_diff {
                curr_len += 1;
            } else {
                curr_len = 1;
            }

            count += curr_len - 1;
            prev_diff = nums[i] - nums[i - 1];
        }

        count
    }
}
