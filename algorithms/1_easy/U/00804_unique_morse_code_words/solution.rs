use std::collections::HashSet;

impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let codes = [
            b".-".to_vec(), b"-...".to_vec(), b"-.-.".to_vec(), b"-..".to_vec(), b".".to_vec(),
            b"..-.".to_vec(), b"--.".to_vec(), b"....".to_vec(), b"..".to_vec(), b".---".to_vec(),
            b"-.-".to_vec(), b".-..".to_vec(), b"--".to_vec(), b"-.".to_vec(), b"---".to_vec(),
            b".--.".to_vec(), b"--.-".to_vec(), b".-.".to_vec(), b"...".to_vec(), b"-".to_vec(),
            b"..-".to_vec(), b"...-".to_vec(), b".--".to_vec(), b"-..-".to_vec(), b"-.--".to_vec(), b"--..".to_vec()
        ];
        let mut hashset: HashSet<Vec<u8>> = HashSet::new();

        for word in words.iter() {
            let mut tmp: Vec<u8> = Vec::new();

            for byte in word.as_bytes() {
                tmp.extend_from_slice(&codes[(*byte - b'a') as usize]);
            }

            hashset.insert(tmp);
        }

        hashset.len() as i32
    }
}
