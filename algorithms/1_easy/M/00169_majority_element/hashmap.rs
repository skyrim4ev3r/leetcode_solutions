use std::collections::HashMap;

impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> i32 {

        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut max_freq_num = 0_i32;
        let mut max_freq_count = 0_i32;

        for num in nums.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        for (num, freq) in freqs.into_iter() {
            if (freq > max_freq_count) {
                max_freq_count = freq;
                max_freq_num = num;
            }
        }

        max_freq_num
    }
}
