impl Solution {
    pub fn maximum_jumps(nums: Vec<i32>, target: i32) -> i32 {
        let len = nums.len();
        let mut dp = vec![-1_i32; len];
        dp[0] = 0;

        for i in 0..len {
            if dp[i] == -1 {
                continue;
            }

            for j in (i + 1)..len {
                if (nums[j] - nums[i]).abs() <= target {
                    dp[j] = dp[j].max(dp[i] + 1);
                }
            }
        }

        dp[len - 1]
    }
}
