impl Solution {
    pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
        let mut buy = i32::MAX;
        let mut profit = 0_i32;

        for price in prices.into_iter() {
            if price - fee > buy {
                profit += price - fee - buy;
                buy = price - fee;
            }

            buy = buy.min(price);
        }

        profit
    }
}
