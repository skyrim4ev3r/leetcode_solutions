impl Solution {
    pub fn max_freq_sum(mut s: String) -> i32 {
        const ALPHABET_LEN: usize = 26;
        let mut freqs = [0; ALPHABET_LEN];

        for ch in s.into_bytes() {
            freqs[(ch - b'a') as usize] += 1;
        }

        let mut max_freqs_vowels = 0;
        let mut max_freqs_consts = 0;
        for i in 0..ALPHABET_LEN {
            if i == 0 || i == 4 || i == 8 || i == 14 || i == 20 {// 'a', 'e', 'i', 'o', 'u'
                max_freqs_vowels = max_freqs_vowels.max(freqs[i]);
            } else {
                max_freqs_consts = max_freqs_consts.max(freqs[i]);
            }
        }

        max_freqs_vowels + max_freqs_consts
    }
}
