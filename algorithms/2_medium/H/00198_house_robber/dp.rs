impl Solution {
    pub fn rob(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();

        if len == 1 {
            return nums[0];
        }

        if len == 2 {
            return nums[0].max(nums[1]);
        }

        nums[2] += nums[0];

        for i in 3..len {
            nums[i] += nums[i - 2].max(nums[i - 3]);
        }

        nums[len - 1].max(nums[len - 2])
    }
}
