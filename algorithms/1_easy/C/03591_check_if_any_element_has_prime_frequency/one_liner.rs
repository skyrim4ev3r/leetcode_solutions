use std::collections::HashMap;
impl Solution {
    pub fn check_prime_frequency(nums: Vec<i32>) -> bool {
        nums.into_iter()
            .fold(HashMap::<i32, i32>::new(), |mut map, num| { *map.entry(num).or_insert(0) += 1; map})
            .into_iter()
            .any(|(_, freq)| freq > 1 && !((2..=(freq as f64).sqrt() as i32).into_iter().any(|i| freq % i == 0)))
    }
}
