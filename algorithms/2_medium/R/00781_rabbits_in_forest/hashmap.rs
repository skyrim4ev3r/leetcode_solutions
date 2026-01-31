use std::collections::HashMap;

impl Solution {
    pub fn num_rabbits(answers: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut count = 0_i32;

        for a in answers.into_iter() {
            *freqs.entry(a).or_insert(0) += 1;
        }

        for (val, freq) in freqs.into_iter() {
            let group_count = (freq + val) / (val + 1);
            count += group_count * (val + 1);
        }

        count
    }
}
