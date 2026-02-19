use std::collections::HashMap;

impl Solution {
    pub fn first_unique_freq(nums: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for &num in nums.iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        let mut freqs_of_freqs: HashMap<i32, i32> = HashMap::new();

        for (_, &freq) in freqs.iter() {
            *freqs_of_freqs.entry(freq).or_insert(0) += 1;
        }

        for &num in nums.iter() {
            let freq = freqs[&num];

            if freqs_of_freqs[&freq] == 1 {
                return num;
            }
        }

        -1
    }
}
