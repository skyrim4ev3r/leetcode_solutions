impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        let mut freqs = [0_i32; 60];
        let mut res = 0_i32;

        for t in time.into_iter() {
            let curr = t % 60;
            let other = (60 - curr) % 60;
            let freq_other = freqs[other as usize];

            res += freq_other;
            freqs[curr as usize] += 1;
        }

        res
    }
}
