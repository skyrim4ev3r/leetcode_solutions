impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let len = words.len();
        let mut res: Vec<String> = Vec::new();
        let mut is_inserted = vec![false; len];

        for i in 0..len {
            for j in 0..len {
                if i == j || is_inserted[j] {
                    continue;
                }

                if let Some(_) = words[i].find(&words[j]) {
                    res.push(words[j].clone());
                    is_inserted[j] = true;
                }
            }
        }

        res
    }
}
