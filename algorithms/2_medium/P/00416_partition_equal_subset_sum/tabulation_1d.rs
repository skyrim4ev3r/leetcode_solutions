impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        debug_assert!(nums.len() > 0 && nums.iter().all(|&n| n >= 0));
        let sum = if cfg!(debug_assertions) {
            nums.iter().try_fold(0_i32, |acc, &x| acc.checked_add(x)).expect("overflow")
        } else {
            nums.iter().map(|x| *x).sum::<i32>()
        };
        if (sum & 1) == 1 { return false; }
        let target = sum / 2;
        let mut dp = vec![false; target as usize + 1];
        dp[target as usize] = true;

        for num in nums.into_iter().rev() {
            if num > target {
                // all nums are positive, so this num cant be use in any subsets
                return false;   
            }

            for i in 0..=((target - num) as usize) {
                dp[i] |= dp[i + num as usize];
            }

            if dp[0] {
                return true;
            }
        }

        false
    }
}
