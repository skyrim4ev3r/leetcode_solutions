impl Solution {
    pub fn earliest_time(tasks: Vec<Vec<i32>>) -> i32 {
        tasks.into_iter().map(|w| w[0] + w[1]).min().unwrap()
    }
}
