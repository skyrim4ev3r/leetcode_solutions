impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut max = 0;

        for sentence in sentences {
            let mut count = 1;
            for byte in sentence.into_bytes() {
                if byte == b' ' {
                    count += 1;
                }
            }

            max = max.max(count);
        }

        max
    }
}
