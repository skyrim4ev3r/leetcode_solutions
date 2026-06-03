impl Solution {
    pub fn minimum_cost(mut cost: Vec<i32>) -> i32 {
        let len = cost.len();
        let mut total_cost = 0_i32;

        cost.sort_unstable_by(|a, b| b.cmp(&a));

        for i in (0..len).step_by(3) {
            total_cost += cost[i] + if i + 1 < len { cost[i + 1] } else { 0 };
        }

        total_cost
    }
}
