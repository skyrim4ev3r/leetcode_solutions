use std::collections::HashMap;

impl Solution {
    pub fn sum_divisible_by_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        let mut sum = 0_i32;

        for num in nums.into_iter() {
            *hashmap.entry(num).or_insert(0) += 1;
        }

        for (key, val) in hashmap.into_iter() {
            if val % k == 0 {
                sum += key * val;
            }
        }

        sum
    }
}
