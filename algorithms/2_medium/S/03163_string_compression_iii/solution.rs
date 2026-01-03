impl Solution {
    pub fn compressed_string(word: String) -> String {
        let bytes = word.as_bytes();
        let len = word.len();
        let mut res: Vec<u8> = Vec::new();
        let mut count = b'0';

        for i in 0..len {
            if i > 0 && bytes[i] == bytes[i - 1] {
                count += 1;
            } else {
                if count > b'0' {
                    res.push(count);
                    res.push(bytes[i - 1]);
                }

                count = b'1';
            }

            if count == b'9' || i == len - 1 {
                res.push(count);
                res.push(bytes[i]);
                count = b'0';
            }
        }

        String::from_utf8(res).unwrap()
    }
}
