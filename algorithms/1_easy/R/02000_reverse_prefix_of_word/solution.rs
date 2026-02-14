impl Solution {
    pub fn reverse_prefix(word: String, mut ch: char) -> String {
        let target_byte = ch as u8; 
        let mut bytes = word.into_bytes();
        let pos = bytes.iter().position(|&x| x == target_byte);

        if let Some(index) = pos {
            bytes[..=index].reverse();
        }

        String::from_utf8(bytes).unwrap()
    }
}
