impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut freqs: [i32; 26] = [0_i32; 26];

        text.into_bytes().into_iter().for_each(|byte| freqs[(byte - b'a') as usize] += 1);

        freqs[(b'b' - b'a') as usize]
        .min(freqs[(b'a' - b'a') as usize])
        .min(freqs[(b'l' - b'a') as usize] / 2)
        .min(freqs[(b'o' - b'a') as usize] / 2)
        .min(freqs[(b'n' - b'a') as usize])
    }
}
