impl Solution {
    pub fn min_deletion(s: String, k: i32) -> i32 {
       let mut freqs = [0_i32; 26];

        s.as_bytes().iter().for_each(|byte| freqs[(*byte - b'a') as usize] += 1);
        freqs.sort_unstable_by(|a, b| b.cmp(&a));

        freqs[k as usize..].iter().sum::<i32>()
    }
}
