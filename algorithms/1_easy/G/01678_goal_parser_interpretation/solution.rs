impl Solution {
    pub fn interpret(command: String) -> String {
        let mut res: Vec<u8> = Vec::with_capacity(command.len());

        for byte in command.into_bytes().into_iter() {
            if byte == b')' {
                if let Some(&res_byte) = res.last() && res_byte == b'(' {
                    res.pop();
                    res.push(b'o');
                }
            } else {
                if let Some(&res_byte) = res.last() && res_byte == b'(' {
                    res.pop();
                }
                res.push(byte);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
