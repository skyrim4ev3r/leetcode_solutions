use std::collections::HashMap;
impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut freqs = HashMap::<u8, u8>::new();

        nums.into_iter().for_each(|num| *freqs.entry(num as u8).or_insert(0) += 1);

        let mut max_freq = 0;
        let mut total = 0;

        freqs.into_iter().for_each(|(_, freq)| {
            if freq > max_freq {
                total = freq;
                max_freq = freq;
            } else if freq == max_freq {
                total += freq;
            }
        });

        total as i32
    }
}
