impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut flags = [0_u8; 128];

        for byte in b"qwertyuiopQWERTYUIOP".iter() {
            flags[*byte as usize] = 1;
        }

        for byte in b"asdfghjklASDFGHJKL".iter() {
            flags[*byte as usize] = 2;
        }

        for byte in b"zxcvbnmZXCVBNM".iter() {
            flags[*byte as usize] = 4;
        }

        for word in words.into_iter() {
            let mut flag = 0_u8;

            for byte in word.as_bytes().iter() {
                flag |= flags[*byte as usize];

                if flag.count_ones() != 1 {
                    break;
                }
            }

            if flag.count_ones() == 1 {
                res.push(word);
            }
        }

        res
    }
}
