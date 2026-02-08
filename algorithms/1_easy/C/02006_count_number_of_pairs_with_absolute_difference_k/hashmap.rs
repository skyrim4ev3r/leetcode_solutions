use std::collections::HashMap;

impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut count = 0_i32;

        for num in nums.into_iter() {
            if let Some(val) = freqs.get(&(num - k)) {
                count += *val;
            }

            if let Some(val) = freqs.get(&(num + k)) {
                count += *val;
            }

            *freqs.entry(num).or_insert(0) += 1;
        }

        count
    }
}
