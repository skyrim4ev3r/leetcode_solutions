use std::collections::HashMap;

impl Solution {
    pub fn min_set_size(arr: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let target_count = ((arr.len() + 1) / 2) as i32;

        for num in arr.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        let mut curr_count = 0_i32;
        let mut curr_count_uniques = 0_i32;
        let freqs_len = freqs.len();
        let freqs_vec = {
            let mut vec = freqs.into_iter().map(|(_, freq)| freq).collect::<Vec<i32>>();
            vec.sort_unstable();
            vec
        };

        for freq in freqs_vec.into_iter().rev() {
            curr_count += freq;
            curr_count_uniques += 1;

            if curr_count >= target_count {
                return curr_count_uniques;
            }
        }

        unreachable!()
    }
}
