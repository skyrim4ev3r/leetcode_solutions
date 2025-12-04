impl Solution {
    pub fn sort_sentence(s: String) -> String {
        let mut arr: Vec<(u8, &str)> = Vec::with_capacity(9);

        for part in s.split_whitespace() {
            arr.push((*part.as_bytes().last().unwrap() - b'0', part));
        }

        arr.sort_unstable_by(|a, b| a.0.cmp(&b.0));

        let mut res: Vec<u8> = Vec::with_capacity(s.len() - arr.len());

        for (_, part) in arr.into_iter() {
            let len = part.len();

            if !res.is_empty() {
                res.push(b' ');
            }

            res.extend_from_slice(&part.as_bytes()[..(len - 1)]);
        }

        String::from_utf8(res).unwrap()
    }
}
