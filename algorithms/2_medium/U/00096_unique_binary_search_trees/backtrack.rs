impl Solution {
    fn backtrack(n: i32, dp: &mut Vec<i32>) -> i32 {
        let mem = dp[n as usize];
        if mem != -1 {
            return mem;
        }

        let mut sum = 0_i32;

        for i in 1..=n {
            sum += Self::backtrack(n - i, dp) * Self::backtrack(i - 1, dp);
        }

        dp[n as usize] = sum;
        sum
    }

    pub fn num_trees(n: i32) -> i32 {
        let mut dp = vec![-1_i32; (n + 1) as usize];
        dp[0] = 1;
        dp[1] = 1;

        Self::backtrack(n, &mut dp)
    }
}
