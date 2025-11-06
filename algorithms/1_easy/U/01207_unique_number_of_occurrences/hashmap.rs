use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut freqs: HashMap<i32, u16> =  HashMap::new();

        for num in arr.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        let freqs_len = freqs.len();
        let freqs_vals_set = freqs.into_iter().map(|(_, val)| val).collect::<HashSet<u16>>();

        freqs_len == freqs_vals_set.len()
    }
}
