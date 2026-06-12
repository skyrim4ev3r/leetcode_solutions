impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        debug_assert!(coins.len() > 0 && amount >= 0);
        let dp_len = amount as usize + 1;
        let mut dp = vec![amount + 1; dp_len];
        dp[0] = 0;

        for c in coins {
            debug_assert!(c > 0);
            let c_usize = c as usize;
            for a in c_usize..dp_len {
                dp[a] = dp[a].min(dp[a - c_usize] + 1);
            }
        }

        if dp[amount as usize] > amount { -1 } else { dp[amount as usize] }
    }
}
