#[derive(Copy, Clone)]
struct DpCell {
    val: i32,
    overflowed: bool,
}

impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        assert!(amount >= 0);
        let mut dp = vec![DpCell{ val: 0, overflowed: false}; 1 + amount as usize];
        dp[0].val = 1;

        for coin in coins {
            for i in coin..=amount { 
                if dp[i as usize].overflowed {
                    // already overflowed, nothing to do
                    continue;
                }

                if dp[(i - coin) as usize].overflowed || dp[(i - coin) as usize].val > i32::MAX - dp[i as usize].val {
                    dp[i as usize].overflowed = true;
                } else {
                    dp[i as usize].val += dp[(i - coin) as usize].val;
                }
            }
        }

        assert!(!dp[amount as usize].overflowed);

        dp[amount as usize].val
    }
}
