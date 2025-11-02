impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        
        let mut curr_min_price = i32::MAX;
        let mut max_profit = 0_i32;

        for price in prices.into_iter() {
            if curr_min_price < price {
                max_profit = max_profit.max(price - curr_min_price);
            } else {
                curr_min_price = price;
            }
        }

        max_profit
    }
}
