use std::collections::HashMap;

impl Solution {
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut max_freq = 0_i32;

        for num in nums.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        for (_, freq) in freqs.iter() {
            max_freq = max_freq.max(*freq);
        }

        let mut res = vec![Vec::<i32>::new(); max_freq as usize];

        for (num, freq) in freqs.into_iter() {
            for i in 0..(freq as usize) {
                res[i].push(num);
            }
        }

        res
    }
}
