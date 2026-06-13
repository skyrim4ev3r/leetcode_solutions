impl Solution {
    const EXACT_ALLOWED_WEIGHTS_LEN: usize = 26;

    pub fn map_word_weights(words: Vec<String>, weights: Vec<i32>) -> String {
        debug_assert!(weights.len() == Self::EXACT_ALLOWED_WEIGHTS_LEN);
        let mut res: Vec<u8> = Vec::with_capacity(words.len());

        for word in words.into_iter() {
            let mut curr_sum = 0_i32;

            for byte in word.into_bytes() {
                debug_assert!(byte >= b'a' && byte <= b'z');
                curr_sum += weights[(byte - b'a') as usize];
            }
    
            let reversed_offset = 25 - (curr_sum % 26);
            res.push(reversed_offset as u8 + b'a');
        }
        
        String::from_utf8(res).unwrap()
    }
}
