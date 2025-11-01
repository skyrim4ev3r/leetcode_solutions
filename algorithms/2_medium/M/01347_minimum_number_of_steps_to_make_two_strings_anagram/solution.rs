impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut freqs = [0_i32; 26];
        for byte in s.into_bytes().into_iter() {
            freqs[(byte - b'a') as usize] += 1;
        }
        for byte in t.into_bytes().into_iter() {
            freqs[(byte - b'a') as usize] -= 1;
        }
        
        // Chars those are in s but not in t will have positive values
        // Chars those are in t but not in s will have negative values
        // Sum of all values will be 0
        // answer is:
        //          sum(abs(freqs)) / 2
        //     or   sum(positive_freqs)
        //     or   abs(sum(negative_freqs))
        //
        // sum(positive_freqs) is more efficent though not noticeable
        freqs.into_iter().filter(|&num| num > 0).sum()
    }
}
