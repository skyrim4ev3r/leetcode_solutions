impl Solution {
    pub fn alternating_sum(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let nums_len = nums.len();

        for i in 0..nums_len {
            if (i & 1) == 0 {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        sum
    }
}
