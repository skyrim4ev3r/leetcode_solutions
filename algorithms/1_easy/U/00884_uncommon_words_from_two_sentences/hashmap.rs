use std::collections::HashMap;

impl Solution {
    
    #[inline(always)]
    fn calac_freqs<'a>(s: &'a str, is_unique: &mut HashMap<&'a str, bool>) {
        for part in s.split_whitespace() {
            is_unique.entry(part).and_modify(|val| *val = false).or_insert(true);
        }
    }

    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut is_unique: HashMap<&str, bool> = HashMap::new();
        Self::calac_freqs(s1.as_str(), &mut is_unique);
        Self::calac_freqs(s2.as_str(), &mut is_unique);
        let mut res: Vec<String> = Vec::new();

        for (word, is_word_unique) in is_unique.into_iter() {
            if is_word_unique {
                res.push(word.to_string());
            }
        }

        res
    }
}
