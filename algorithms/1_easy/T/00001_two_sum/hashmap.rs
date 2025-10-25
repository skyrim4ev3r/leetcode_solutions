use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {

        let mut hashmap: HashMap<i32, i32> = HashMap::new();

        for (curr_index, num) in nums.into_iter().enumerate() {

            if let Some(other_index) = hashmap.get(&(target - num)) {
                return vec![*other_index, curr_index as i32];
            }

            hashmap.insert(num, curr_index as i32);
        }

        Vec::new()
    }
}
