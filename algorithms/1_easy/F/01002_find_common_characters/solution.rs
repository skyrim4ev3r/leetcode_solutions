impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut max_freqs = [i32::MAX; 26];

        for word in words.iter() {
            let mut freqs = [0_i32; 26];

            for byte in word.as_bytes().iter() {
                freqs[(*byte - b'a') as usize] += 1;
            }

            for i in 0..26 {
                max_freqs[i]= max_freqs[i].min(freqs[i]);
            }
        }

        let mut res: Vec<String> = Vec::new();
         for i in 0..26 {
           let temp = ((i as u8 + b'a') as char).to_string();

            for _ in 0..max_freqs[i] {
                res.push(temp.clone());
            }
         }

         res
    }
}
