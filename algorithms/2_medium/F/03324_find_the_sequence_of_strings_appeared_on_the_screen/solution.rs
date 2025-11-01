impl Solution {
    pub fn string_sequence(target: String) -> Vec<String> {

        let mut screen: Vec<u8> = Vec::with_capacity(target.len());
        let mut res: Vec<String> = Vec::new();

        for byte in target.into_bytes().into_iter() {
            screen.push(0);

            for last_byte in b'a'..=byte {
                *screen.last_mut().unwrap() = last_byte;
                res.push(String::from_utf8_lossy(&screen).into_owned());
            }
        }

        res
    }
}
