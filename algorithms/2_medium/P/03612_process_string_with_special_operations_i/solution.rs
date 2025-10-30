impl Solution {
    pub fn process_str(s: String) -> String {

        let mut res: Vec<u8> = Vec::new();

        for ch in s.into_bytes() {
            if ch >= b'a' && ch <= b'z' {
                res.push(ch);
            } else if ch == b'#' {
                res.extend(res.clone());
            } else if ch == b'%' {
                res.reverse();
            } else {
                res.pop();
            }
        }

        String::from_utf8(res).unwrap_or(String::from(""))
    }
}
