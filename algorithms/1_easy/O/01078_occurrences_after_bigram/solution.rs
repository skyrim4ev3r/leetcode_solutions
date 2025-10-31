impl Solution {
    pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String> {

        let mut res: Vec<String> = Vec::new();

        for window in text.split_whitespace().collect::<Vec<&str>>().windows(3) {
            if window[0] == &first && window[1] == &second {
                res.push(String::from_utf8_lossy(window[2].as_bytes()).into_owned());
            }
        }

        res
    }
}
