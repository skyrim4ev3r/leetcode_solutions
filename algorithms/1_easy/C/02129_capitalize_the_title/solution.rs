impl Solution {
    pub fn capitalize_title(title: String) -> String {
        let mut res: Vec<u8> = Vec::with_capacity(title.len());
        let words: Vec<&str> = title.split_whitespace().collect();

        for (i, part) in words.iter().enumerate() {
            if i > 0 {
                res.push(b' ');
            }

            let bytes = part.as_bytes();

            if bytes.len() < 3 {
                res.push(bytes[0].to_ascii_lowercase());
            } else {
                res.push(bytes[0].to_ascii_uppercase());
            }

            for byte in bytes[1..].iter() {
                res.push(byte.to_ascii_lowercase());
            }
        }

        String::from_utf8(res).unwrap()
    }
}
