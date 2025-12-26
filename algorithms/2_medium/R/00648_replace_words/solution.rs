impl Solution {
    pub fn replace_words(mut dictionary: Vec<String>, sentence: String) -> String {
        dictionary.sort_unstable_by(|a, b| a.len().cmp(&b.len()));
        let mut res = Vec::<&str>::new();

        for word in sentence.split_whitespace() {
            let mut is_inserted = false;

            for d in dictionary.iter() {
                if word.starts_with(d) {
                    res.push(d.as_str());
                    is_inserted = true;
                    break;
                }
            }

            if !is_inserted {
                res.push(word);
            }
        }

        res.join(" ")
    }
}
