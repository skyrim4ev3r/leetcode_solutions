impl Solution {
    fn backtrack(
        memo: &mut [i32],
        nums: &[i32],
        target: i32,
    ) -> i32 {
        if target == 0 { return 1; }
        if target < 0 { return 0; }
        if memo[target as usize] != -1 { return memo[target as usize]; }

        let mut res = 0;

        for &num in nums {
            res += Self::backtrack(memo, nums, target - num);
        }

        memo[target as usize] = res;
        res
    } 

    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        debug_assert!(target > 0);
        let mut memo = vec![-1; target as usize + 1];

        return Self::backtrack(&mut memo, &nums, target);
    }
}
