use std::collections::HashMap;

impl Solution {
    pub fn is_possible_to_split(nums: Vec<i32>) -> bool {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in nums.iter() {
            let freq = freqs.entry(*num).or_insert(0);
            *freq += 1;

            if *freq > 2 {
                return false;
            }
        }

        true
    }
}
