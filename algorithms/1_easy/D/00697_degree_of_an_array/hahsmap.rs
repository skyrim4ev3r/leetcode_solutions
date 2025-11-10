use std::collections::HashMap;

impl Solution {
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, (i32, usize, usize)> = HashMap::new();

        for (index, num) in nums.into_iter().enumerate() {
            let info = freqs.entry(num).or_insert((0, index, index));
            info.0 += 1;
            info.2 = index;
        }

        let mut max_freq = 0_i32;
        let mut min_width = usize::MAX;

        for (_, (freq, left, right)) in freqs.into_iter() {
            if freq > max_freq {
                max_freq = freq;
                min_width = right - left + 1;
            } else if freq == max_freq {
                min_width = min_width.min(right - left + 1);
            }
        }

        min_width as i32
    }
}
