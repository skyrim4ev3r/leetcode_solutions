impl Solution {
    pub fn max_ice_cream(mut costs: Vec<i32>, mut coins: i32) -> i32 {
        costs.sort_unstable();
        let mut count = 0_i32;

        for cost in costs.into_iter() {
            if cost <= coins {
                coins -= cost;
                count += 1;
            } else {
                break;
            }
        }

        count
    }
}
