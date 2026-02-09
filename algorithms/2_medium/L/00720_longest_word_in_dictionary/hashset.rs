use std::collections::HashSet;

impl Solution {
    pub fn longest_word(mut words: Vec<String>) -> String {
        words.sort_unstable_by_key(|x| x.len());

        let mut valids: HashSet<&str> = HashSet::new();
        let mut max_seen_len = 0_usize;

        for w in words.iter() {
            let curr_word_len = w.len();

            if curr_word_len > max_seen_len + 1 {
                break;
            }

            if curr_word_len > 1 && !valids.contains(&w[..curr_word_len - 1]) {
                continue;
            }

            max_seen_len = curr_word_len;
            valids.insert(w);
        }

        let mut valid_vec = valids.into_iter()
                                  .filter(|x| x.len() == max_seen_len)
                                  .collect::<Vec<_>>();
        valid_vec.sort_unstable();

        valid_vec.get(0).unwrap_or(&"").to_string()
    }
}
