impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let word1_bytes = word1.into_bytes();
        let word2_bytes = word2.into_bytes();
        let len1 = word1_bytes.len();
        let len2 = word2_bytes.len();
        let mut res: Vec<u8> = Vec::with_capacity(len1 + len2);

        let min_len = len1.min(len2);

        for index in 0..min_len {
            res.push(word1_bytes[index]);
            res.push(word2_bytes[index]);
        }

        res.extend_from_slice(&word1_bytes[min_len..len1]);
        res.extend_from_slice(&word2_bytes[min_len..len2]);

        String::from_utf8(res).unwrap()
    }
}
