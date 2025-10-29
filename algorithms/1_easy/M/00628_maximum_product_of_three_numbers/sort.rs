impl Solution {
    pub fn maximum_product(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();

        nums.sort_unstable();

        (nums[0] * nums[1] * nums[len - 1]).max(nums[len - 1] * nums[len - 2] * nums[len - 3])
    }
}
