use std::collections::HashMap;

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let mut sum = 0_i32;
        let mut map: HashMap<i32, u8> = HashMap::new();
        
        for num in nums.into_iter() {
            *map.entry(num).or_insert(0_u8) += 1_u8;
        }

        for (num, count) in map.into_iter() {
            if count == 1 {
                sum += num;
            }
        }

        sum
    }
}
