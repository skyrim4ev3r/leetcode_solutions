impl Solution {
    pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
        if (hour.ceil() as usize) <= dist.len() - 1 {
            return -1;
        }

        let mut high = 10_000_000_i32;
        let mut low = 1_i32;
        let len = dist.len();

        while low <= high {
            let mid = low + (high - low) / 2;
            let curr_cost_i32 = dist[0..(len - 1)].iter().map(|x| (*x + mid - 1) / mid).sum::<i32>();
            let curr_cost = (curr_cost_i32 as f64) + (dist[len - 1] as f64) / (mid as f64);

            if curr_cost <= hour {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low
    }
}
