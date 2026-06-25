impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i64 {
        let len = nums.len();
        if len <= 1 { return 0; }
        let mut res = 0_i64;

        for i in 1..len {
            if nums[i - 1] >= nums[i] {
                res += (nums[i - 1] - nums[i]) as i64;
            }
        }

        res
    }
}
