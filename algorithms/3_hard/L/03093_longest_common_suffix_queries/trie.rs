use std::collections::HashMap;

struct Trie {
    children: HashMap<u8, Trie>,
    winner_word_idx_in_list: i32,
    winner_word_len: i32,
}

impl Trie {

    #[inline]
    fn new(word_idx_in_list: i32, word_len: i32) -> Self {
        Self {
            children: HashMap::new(),
            winner_word_idx_in_list: word_idx_in_list,
            winner_word_len: word_len,
        }
    }

    fn from_words(words: &[String]) -> Self {

        #[inline]
        fn insert_word(head_trie: &mut Trie, word: &str, word_idx_in_list: i32) {
            let word_len = word.len() as i32;
            let mut curr_trie = head_trie;

            if word_len < curr_trie.winner_word_len {
                curr_trie.winner_word_len = word_len;
                curr_trie.winner_word_idx_in_list = word_idx_in_list;
            }

            for &byte in word.as_bytes().iter().rev() {
                curr_trie = curr_trie.children.entry(byte).or_insert(Trie::new(word_idx_in_list, word_len));

                if word_len < curr_trie.winner_word_len {
                    curr_trie.winner_word_len = word_len;
                    curr_trie.winner_word_idx_in_list = word_idx_in_list;
                }
            }
        }

        let mut res = Self::new(0, words[0].len() as i32);

        for (i, word) in words.iter().enumerate() {
            insert_word(&mut res, &word, i as i32);
        }

        res
    }

    fn longest_common_suffix(&self, word: &[u8]) -> i32 {
        let mut curr_trie = self;

        for byte in word.iter().rev() {
            match curr_trie.children.get(byte) {
                Some(next_trie) => curr_trie = next_trie,
                None => break,
            }
        }

        curr_trie.winner_word_idx_in_list
    }
}

impl Solution {
    pub fn string_indices(words_container: Vec<String>, words_query: Vec<String>) -> Vec<i32> {
        let mut trie = Trie::from_words(&words_container);
        let mut res: Vec<i32> = Vec::with_capacity(words_query.len());

        for w in words_query.iter() {
            res.push(trie.longest_common_suffix(w.as_bytes()));
        }

        res
    }
}
