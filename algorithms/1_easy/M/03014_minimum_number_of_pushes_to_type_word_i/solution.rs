impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        let mut freqs = [0_i32; 26];

        for byte in word.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        freqs.sort_unstable_by(|a, b| b.cmp(&a));

        freqs[0..8].iter().map(|x| *x).sum::<i32>() +
        freqs[8..16].iter().map(|x| *x).sum::<i32>() * 2 +
        freqs[16..24].iter().map(|x| *x).sum::<i32>() * 3 +
        freqs[24..26].iter().map(|x| *x).sum::<i32>() * 4
    }
}
