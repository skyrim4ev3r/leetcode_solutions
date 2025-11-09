impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return 0; // No range to consider
        }

        nums.sort_unstable();

        let len = nums.len();
        let mut left = 0 as usize;
        let mut right = k as usize - 1;
        let mut min_difference = std::i32::MAX; // Initialize to maximum possible value

        while right < len {
            min_difference = min_difference.min(nums[right] - nums[left]);
            left += 1;
            right += 1;
        }

        min_difference
    }
}
