use std::collections::HashMap;

impl Solution {
    pub fn largest_vals_from_labels(
        values: Vec<i32>,
        labels: Vec<i32>,
        num_wanted: i32,
        use_limit: i32,
    ) -> i32 {
        let mut arr = values.into_iter().zip(labels.into_iter()).collect::<Vec<_>>();
        arr.sort_unstable_by(|a, b| b.0.cmp(&a.0));
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut res = 0_i32;
        let mut count = 0_i32;

        for (val, label) in arr.into_iter() {
            if count >= num_wanted {
                break;
            }

            let entry = freqs.entry(label).or_insert(0);

            if *entry < use_limit {
                *entry += 1;
                count += 1;
                res += val;
            }
        }

        res
    }
}
