impl Solution {
    pub fn decode_message(key: String, message: String) -> String {

        let mut key_map = [0_u8; 26];

        let mut curr_char = b'a';
        for ch in key.into_bytes().into_iter() {

            let index = (ch - b'a') as usize;
    
            if ch != b' ' && key_map[index] == 0 {
                key_map[index] = curr_char;
                curr_char += 1;
            }
        }

        let message_bytes = message.into_bytes();
        let mut res: Vec<u8> = Vec::with_capacity(message_bytes.len());

        for ch in message_bytes.into_iter() {
            if ch == b' ' {
                res.push(ch);
            } else {
                res.push(key_map[(ch - b'a') as usize]);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
