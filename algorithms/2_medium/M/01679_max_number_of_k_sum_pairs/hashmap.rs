use std::collections::HashMap;

impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {

        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut count = 0_i32;

        for num in nums.into_iter() {
            let other = k - num;

            if let Some(val) = map.get_mut(&other) && *val > 0 {
                *val -= 1;
                count += 1;
            } else {
                *map.entry(num).or_insert(0) += 1;
            }
        }

        count
    }
}
