impl Solution {
    #[inline(always)]
    pub fn rob_helper(slice: &[i32]) -> i32 {
        let (mut prev_prev, mut prev, mut curr) = (0_i32, 0_i32, 0_i32);

        for &num in slice {
            debug_assert!(num >= 0);
            let next = num + prev.max(prev_prev);
            (prev_prev, prev, curr) = (prev, curr, next);
        }

        prev.max(curr)
    }

    pub fn rob(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        debug_assert!(len > 0);

        if len == 1 {
            debug_assert!(nums[0] >= 0);
            return nums[0];
        }

        let max_dp1 = Self::rob_helper(&nums[0..len - 1]);
        let max_dp2 = Self::rob_helper(&nums[1..len]);

        max_dp1.max(max_dp2)
    }
}
