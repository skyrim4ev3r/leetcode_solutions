impl Solution {
    pub fn process_str(s: String) -> String {
        let mut res: Vec<u8> = Vec::new();

        for byte in s.into_bytes() {
            match byte {
                b'#' => res.extend_from_within(0..res.len()),
                b'a'..=b'z' => res.push(byte),
                b'*' => drop(res.pop()),
                b'%' => res.reverse(),
                _ => unreachable!("invalid input")
            };
        }

        String::from_utf8(res).unwrap()
    }
}
