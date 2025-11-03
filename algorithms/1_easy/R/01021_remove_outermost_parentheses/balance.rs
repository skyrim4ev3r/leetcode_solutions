impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {

        let mut res: Vec<u8> = Vec::new();
        let mut balance = 0_i32;

        for byte in s.into_bytes().into_iter() {
            if byte == b'(' {
                balance += 1;
            } else {
                balance -= 1;
            }

            if (balance == 1 && byte == b'(') || balance == 0 {
               continue;
            }

            res.push(byte);
        }

        String::from_utf8(res).unwrap()
    }
}
