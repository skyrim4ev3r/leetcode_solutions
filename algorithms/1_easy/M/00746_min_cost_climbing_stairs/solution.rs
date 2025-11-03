impl Solution {
    pub fn min_cost_climbing_stairs(mut cost: Vec<i32>) -> i32 {
        let len = cost.len();

        for i in (0..(len - 2)).rev() {
            cost[i] += cost[i + 1].min(cost[i + 2]);
        }

        return cost[0].min(cost[1]);
    }
}
