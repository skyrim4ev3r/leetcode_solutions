impl Solution {
    pub fn min_difference(mut nums: Vec<i32>) -> i32 {
        const target_steps: usize = 3;
        let len = nums.len();

        if len <= target_steps + 1 {
            return 0;
        }

        nums.sort_unstable();

        let mut min_diff = i32::MAX;

        for i in 0..=target_steps {
            let j = len - (target_steps - i) - 1;
            min_diff = min_diff.min(nums[j] - nums[i]);
        }

        min_diff
    }
}
