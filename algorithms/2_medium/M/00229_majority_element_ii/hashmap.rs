use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let min_target_freq = 1 + (nums.len() as i32) / 3;
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut res: Vec<i32> = Vec::new();

        for num in nums.into_iter() {
            freqs.entry(num).and_modify(|x| *x += 1).or_insert(1);
        }

        for (val, freq) in freqs.into_iter() {
            if freq >= min_target_freq {
                res.push(val);
            }
        }

        res
    }
}
