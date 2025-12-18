impl Solution {
    pub fn max_profit(prices: Vec<i32>, strategy: Vec<i32>, k: i32) -> i64 {
        let len = prices.len();
        let mut prefix = vec![0_i64; len + 1];
        let k_usize = k as usize;

        for i in 0..len {
            prefix[i + 1] = prefix[i] + (prices[i] as i64 * strategy[i] as i64);
        }

        let mut curr = prices[(k_usize / 2)..k_usize].iter().map(|x| *x as i64).sum::<i64>();
        let mut max = prefix[len];
        max = max.max(prefix[len] - prefix[k_usize] + curr);

        for i in k_usize..len {
            curr = curr - prices[i - (k_usize / 2)] as i64 + prices[i] as i64;
            max = max.max(prefix[len] - prefix[i + 1] + prefix[i - k_usize + 1] + curr);
        }

        max
    }
}
