use std::collections::HashMap;

impl Solution {
    pub fn find_least_num_of_unique_ints(arr: Vec<i32>, mut k: i32) -> i32 {
        let len = arr.len();

        if k as usize >= len {
            return 0;
        }

        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for a in arr.into_iter() {
            *freqs.entry(a).or_insert(0) += 1;
        }

        let mut freqs_val = freqs.values().cloned().collect::<Vec<_>>();
        freqs_val.sort_unstable_by(|a, b| b.cmp(&a));

        while let Some(val) = freqs_val.last() && k >= *val {
            k -= *val;
            freqs_val.pop();
        }

        freqs_val.len() as i32
    }
}
