impl Solution {
    pub fn min_costs(mut cost: Vec<i32>) -> Vec<i32> {
        for i in 1..cost.len() {
            cost[i] = cost[i].min(cost[i - 1]);
        }

        cost
    }
}
