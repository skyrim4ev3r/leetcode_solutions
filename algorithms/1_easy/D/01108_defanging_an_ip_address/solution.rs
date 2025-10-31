impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut res: Vec<u8> = Vec::with_capacity(address.len());

        for byte in address.into_bytes().into_iter() {
            if byte == b'.' {
                res.extend([b'[', b'.', b']']);
            } else {
                res.push(byte);
            }
        }
        
        String::from_utf8(res).unwrap()
    }
}
