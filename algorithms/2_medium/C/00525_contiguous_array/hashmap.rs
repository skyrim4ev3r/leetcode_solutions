use std::collections::HashMap;

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let mut diff_to_len_map: HashMap<i32, usize> = HashMap::new();
        let mut count_zeros = 0_i32;
        let mut count_ones = 0_i32;
        let mut longest = 0_usize;

        diff_to_len_map.insert(0, 0);

        for (i, num) in nums.iter().enumerate() {
            match *num {
                1 => count_ones += 1,
                _ => count_zeros += 1,
            }

            let prev_len = diff_to_len_map.entry(count_ones - count_zeros).or_insert(i + 1);
            longest = longest.max(i + 1 - *prev_len);
        }

        longest as i32
    }
}
