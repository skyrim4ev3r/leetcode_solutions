use std::collections::HashMap;

impl Solution {
    pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut count_pair = 0_i32;
        let mut count_leftover = 0_i32;

        for num in nums.iter() {
            *freqs.entry(*num).or_insert(0) += 1;
        }

        for (_, freq) in freqs.iter() {
            count_pair += *freq / 2;
            count_leftover += (*freq & 1);
        }

       vec![count_pair, count_leftover]
    }
}
