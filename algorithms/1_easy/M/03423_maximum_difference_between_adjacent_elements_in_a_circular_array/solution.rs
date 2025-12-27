impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        let mut max_diff = (nums[nums.len() - 1] - nums[0]).abs();

        for w in nums.windows(2) {
            max_diff = max_diff.max((w[1] - w[0]).abs());
        }

        max_diff
    }
}
