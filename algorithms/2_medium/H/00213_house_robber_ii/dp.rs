impl Solution {
    #[inline(always)]
    pub fn rob_helper(dp: &mut Vec<i32>) -> i32 {
        let len = dp.len();

        dp[2] += dp[0];

        for i in 3..len {
            dp[i] += dp[i - 2].max(dp[i - 3]);
        }

        dp[len - 1].max(dp[len - 2])
    }

    pub fn rob(mut nums: Vec<i32>) -> i32 {
        if nums.len() <= 3 {
            return nums.into_iter().max().unwrap();
        }

        let mut dp1 = nums[1..].to_vec();
        nums.pop();
        let mut dp2 = nums;

        let max_dp1 = Self::rob_helper(&mut dp1);
        let max_dp2 = Self::rob_helper(&mut dp2);

        max_dp1.max(max_dp2)
    }
}
