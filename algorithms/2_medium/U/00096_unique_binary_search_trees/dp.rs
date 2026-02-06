impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let mut dp = vec![0_i32; (n + 1) as usize];
        dp[0] = 1;
        dp[1] = 1;

        for i in 2..=(n as usize) {
            for j in 1..=i {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }

        dp[n as usize]
    }
}
