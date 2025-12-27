impl Solution {
    pub fn max_difference(s: String) -> i32 {
        let mut min_even = i32::MAX;
        let mut max_odd = i32::MIN;
        let mut freqs = [0_i32; 26];

        for byte in s.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        for &freq in freqs.iter() {
            if freq > 0 {
                if (freq & 1) == 1 {
                    max_odd = max_odd.max(freq);
                } else {
                    min_even = min_even.min(freq);
                }
            }
        }

        max_odd - min_even
    }
}
