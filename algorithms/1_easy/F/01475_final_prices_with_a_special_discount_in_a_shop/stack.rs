impl Solution {
    pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        let len = prices.len();
        let mut res = vec![0_i32; len];

        for i in (0..len).rev() {
            while let Some(val) = stack.last() && *val > prices[i] {
                stack.pop();
            }

            if  let Some(val) = stack.last() {
                res[i] = prices[i] - *val;
            } else {
                res[i] = prices[i];
            }

            stack.push(prices[i]);
        }

        res
    }
}
