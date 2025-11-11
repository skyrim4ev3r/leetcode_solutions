impl Solution {
    pub fn remove_occurrences(mut s: String, part: String) -> String {
        let part_len = part.len();

        while let Some(pos) = s.find(&part) {
            s = format!("{}{}", &s[..pos], &s[pos + part_len..]);
        }

        s
    }
}
