impl Solution {
    pub fn min_cost(mut n: i32) -> i32 {
        assert!(n > 0);
        if n == 1 { return 0; }
        if n == 2 { return 1; }

        let mut dp = vec![0_i32; n as usize + 1];
        dp[1] = 0;
        dp[2] = 1;

        for i in 3..=n {
            let half = i / 2;
            let other = i - half;
            dp[i as usize] = (half * other) + dp[half as usize] + dp[other as usize];
        }

        dp[n as usize]
    }
}
