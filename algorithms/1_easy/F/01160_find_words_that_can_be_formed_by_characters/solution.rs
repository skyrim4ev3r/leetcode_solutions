impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {

        let mut freqs_chars = [0_i32; 26];
        chars.into_bytes().into_iter().for_each(|x| freqs_chars[(x - b'a') as usize] += 1);
        let mut count = 0_i32;

        for word in words.into_iter() {
            let mut freqs  = [0_i32; 26];
            let word_len = word.len();
            word.into_bytes().into_iter().for_each(|x| freqs[(x - b'a') as usize] += 1);

            let mut is_ans = true;
            for i in 0..26 {
                if freqs[i] > freqs_chars[i] {
                    is_ans = false;
                    break;
                }
            }

            if is_ans {
                count += word_len as i32;
            }
        }

        count
    }
}
