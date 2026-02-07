impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let dp_len = (1 + *nums.iter().max().unwrap()) as usize;
        let mut dp = vec![0; dp_len];

        for num in nums.into_iter() {
            dp[num as usize] += num;
        }

        for i in 3..dp_len {
            dp[i] += dp[i - 2].max(dp[i - 3]);
        }

        dp[dp_len - 1].max(dp[dp_len - 2])
    }
}
