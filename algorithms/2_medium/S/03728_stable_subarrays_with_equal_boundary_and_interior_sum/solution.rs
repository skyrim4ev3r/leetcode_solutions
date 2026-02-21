use std::collections::HashMap;

impl Solution {
    const MIN_WIDTH: usize = 3;

    pub fn count_stable_subarrays(capacity: Vec<i32>) -> i64 {
        let len = capacity.len();
        let mut count = 0_i64;
        let mut pref_sum_left = 0_i64;
        let mut pref_sum_right = 0_i64;
        let mut freqs: HashMap<(i64, i32), i32> = HashMap::new();

        for i in 0..len {
            if i >= (Self::MIN_WIDTH - 1) {
                let val_left = capacity[i - (Self::MIN_WIDTH - 1)];
                pref_sum_left += val_left as i64;
                *freqs.entry((pref_sum_left, val_left)).or_insert(0) += 1;
            }

            let val_right = capacity[i];
            pref_sum_right += val_right as i64;
            let other_sum = pref_sum_right - (2 * val_right as i64);
            if let Some(freq) = freqs.get(&(other_sum, val_right)) {
                count += *freq as i64;
            }
        }

        count
    }
}
