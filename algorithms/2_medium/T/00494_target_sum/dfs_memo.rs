impl Solution {
    fn dfs(
        nums: &[i32],
        len: usize,
        curr_idx: usize,
        curr_sum: i32,
        target: i32,
        sum_abs: i32,
        memo: &mut [i32],
        memo_cols: usize,
    ) -> i32 {
        if curr_idx == len {
            return if curr_sum == target { 1 } else { 0 };
        }

        let memo_idx = (curr_idx * memo_cols) + (curr_sum + sum_abs) as usize;

        if memo[memo_idx] != - 1 {
            return memo[memo_idx];
        }

        let res = Self::dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, sum_abs, memo, memo_cols) +
                  Self::dfs(nums, len, curr_idx + 1, curr_sum - nums[curr_idx], target, sum_abs, memo, memo_cols);

        memo[memo_idx] = res;
        res
    }

    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let len = nums.len();
        let sum_abs = nums.iter().map(|x| x.abs()).sum::<i32>();
        let memo_rows = len;
        let memo_cols = 1 + 2 * (sum_abs as usize); // for all vals in range [-sum_abs, sum_abs]
        debug_assert!(usize::MAX / memo_cols >= memo_rows);
        let mut memo = vec![-1_i32; memo_rows * memo_cols];
        return Self::dfs(&nums, len, 0, 0, target, sum_abs, &mut memo, memo_cols);
    }
}
