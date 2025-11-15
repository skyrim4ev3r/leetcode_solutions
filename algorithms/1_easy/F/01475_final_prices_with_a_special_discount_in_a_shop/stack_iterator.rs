impl Solution {
    pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        let len = prices.len();
        let mut res = vec![0_i32; len];

        for (it, it_res) in prices.iter().rev().zip(res.iter_mut().rev()) {
            while let Some(val) = stack.last() && *val > *it {
                stack.pop();
            }

            if  let Some(val) = stack.last() {
                *it_res = *it - *val;
            } else {
                *it_res = *it;
            }

            stack.push(*it);
        }

        res
    }
}
