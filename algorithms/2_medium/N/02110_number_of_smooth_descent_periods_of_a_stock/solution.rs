impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let len = prices.len();
        let mut count = 0_i64;
        let mut i = 0_usize;

        while i < len {
            let mut continues = 1;

            while i + 1 < len && prices[i] - 1 == prices[i + 1] {
                i += 1;
                continues += 1;
            }

            count += continues * (continues + 1) / 2;
            i += 1;
        }

        count
    }
}
