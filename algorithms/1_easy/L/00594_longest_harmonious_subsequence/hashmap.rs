use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in nums.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        let mut longest = 0_i32;

        for (&val, &freq) in freqs.iter() {
            if let Some(&next_val) = freqs.get(&(val + 1)) {
                longest = longest.max(freq + next_val);
            }

            if let Some(&prev_val) = freqs.get(&(val - 1)) {
                longest = longest.max(freq + prev_val);
            }
        }

        longest
    }
}
