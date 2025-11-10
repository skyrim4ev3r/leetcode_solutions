impl Solution {
    const MAX_SIZE: usize = 99;

    pub fn generate_tag(caption: String) -> String {
        let mut res: Vec<u8> = Vec::new();
        res.push(b'#');
        for word in caption.split_whitespace() {

            // 1- to_lower() for all ascii chars in word 
            // 2- .take(MAX_SIZE)
            let mut bytes: Vec<u8> = word.as_bytes()
                                        .to_vec()
                                        .iter()
                                        .take(Self::MAX_SIZE)
                                        .map(|&c| if c >= b'A' && c <= b'Z' {c + 32} else {c})
                                        .collect();

            // to_upper() for first ascii char 
            bytes[0] -= 32;

            res.extend(bytes);

            if res.len() >= Self::MAX_SIZE {
                break;
            }
        }

        // convert the first char of the first word to lower_case() if it exists
        if res.len() > 1 {
            res[1] += 32;
        }

        String::from_utf8(res).unwrap_or(String::from("#error"))
    }
}
