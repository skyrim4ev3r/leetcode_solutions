impl Solution {
    const FREQS_LEN: usize = 10;
    pub fn digit_frequency_score(mut n: i32) -> i32 {
        let mut freqs = [0_i32; Self::FREQS_LEN];

        while n > 0 {
            freqs[(n % 10) as usize] += 1;
            n /= 10;
        }

        let mut score = 0_i32;

        for (i, freq) in freqs.into_iter().enumerate() {
            score += i as i32 * freq;
        }

        score
    }
}
