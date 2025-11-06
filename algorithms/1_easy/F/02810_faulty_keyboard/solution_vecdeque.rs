use std::collections::VecDeque;

impl Solution {
    pub fn final_string(s: String) -> String {

        let mut res: VecDeque<u8> = VecDeque::new();
        let mut should_reverse = false;

        for byte in s.into_bytes().into_iter() {
            if byte == b'i' {
                should_reverse = !should_reverse;
            } else {
                if should_reverse {
                    res.push_front(byte);
                } else {
                    res.push_back(byte);
                }
            }
        }

        if should_reverse {
            res.make_contiguous().reverse();
        }
        let res_vec: Vec<u8> = res.into();

        String::from_utf8(res_vec).unwrap()
    }
}
