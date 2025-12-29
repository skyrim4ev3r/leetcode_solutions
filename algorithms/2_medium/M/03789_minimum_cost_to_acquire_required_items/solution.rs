impl Solution {
    fn minimum_cost_i64(cost1: i64, cost2: i64, cost_both: i64, need1: i64, need2: i64) -> i64 {
        let buy_seperate: i64 = (cost1 * need1) + (cost2 * need2);
        let buy_together: i64 = {
            let buy_base_together = need1.min(need2) * cost_both;
            let buy_extra_together = cost_both * (need2 - need1).abs();
            let buy_extra_seperate = if need2 > need1 {cost2 * (need2 - need1)} else {cost1 * (need1 - need2)};

            buy_base_together + buy_extra_seperate.min(buy_extra_together)
        };

        buy_together.min(buy_seperate)
    }
    pub fn minimum_cost(cost1: i32, cost2: i32, cost_both: i32, need1: i32, need2: i32) -> i64 {
        Self::minimum_cost_i64(cost1 as i64, cost2 as i64, cost_both as i64, need1 as i64, need2 as i64)
    }
}
