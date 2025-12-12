use std::collections::HashMap;

impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for i in 1..=n {
            let mut temp = i;
            let mut dig_sum = 0_i32;

            while temp > 0 {
                dig_sum += temp % 10;
                temp /= 10;
            }

            *freqs.entry(dig_sum).or_insert(0) += 1;
        }

        let mut max_freq = 0_i32;
        let mut max_freq_count = 0_i32;

        for freq in freqs.values() {
            if *freq > max_freq {
                max_freq = *freq;
                max_freq_count = 1;
            } else if *freq == max_freq {
                max_freq_count += 1;
            }
        }

        max_freq_count
    }
}
