impl Solution {
    pub fn final_string(s: String) -> String {

        let mut res: Vec<u8> = Vec::new();
        let mut should_reverse = false;

        for byte in s.into_bytes().into_iter() {
            if byte == b'i' {
                should_reverse = !should_reverse;
            } else {
                if should_reverse {
                    res.reverse();
                    should_reverse = false;
                }
                res.push(byte);
            }
        }

        if should_reverse {
            res.reverse();
        }

        String::from_utf8(res).unwrap()
    }
}
