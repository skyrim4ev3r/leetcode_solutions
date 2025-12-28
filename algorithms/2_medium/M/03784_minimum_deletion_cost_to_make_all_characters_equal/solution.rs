impl Solution {
    pub fn min_cost(s: String, cost: Vec<i32>) -> i64 {
        let len = s.len();
        let bytes = s.as_bytes();
        let mut cost_chars = [0_i64; 26];
        let mut total_cost = 0_i64;

        for i in 0..len {
            cost_chars[(bytes[i] - b'a') as usize] += cost[i] as i64;
            total_cost += cost[i] as i64;
        }

        let mut max = 0_i64;

        for cost_char in cost_chars.into_iter() {
            max = max.max(cost_char);
        }

        total_cost - max
    }
}
