use std::collections::HashMap;

struct Trie {
    next: HashMap<u8, Box<Trie>>,
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Self {
            next: HashMap::new(),
            is_end: false
        }
    }

    fn insert(&mut self, key: &str) {
        let mut curr = self;

        for &byte in key.as_bytes().iter() {
            curr = &mut *curr.next.entry(byte).or_insert(Box::new(Trie::new()));
        }

        curr.is_end = true;
    }

    fn search_with_exact_diff(&self, prefix: &[u8], diff_count: i32) -> bool {
        const CURR_INDEX: usize = 0_usize;

        self.dfs_search_with_exact_diff(prefix, CURR_INDEX, diff_count)
    }

    fn dfs_search_with_exact_diff(
        &self,
        prefix: &[u8],
        curr_index: usize,
        curr_diff_left: i32,
    ) -> bool {
        if curr_index == prefix.len() {
            return curr_diff_left == 0 && self.is_end;
        }

        let curr_byte = prefix[curr_index];

        if curr_diff_left > 0 {
            for (&byte_key, next) in self.next.iter() {
                if byte_key == curr_byte {
                    if next.dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left) {
                        return true;
                    }
                } else {
                    if next.dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left - 1) {
                        return true;
                    }
                }
            }
        } else {
            if let Some(next) = self.next.get(&curr_byte) {
                if next.dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left) {
                    return true;
                }
            }
        }

        false
    }
}

struct MagicDictionary {
    trie: Box<Trie>,
}

impl MagicDictionary {
    fn new() -> Self {
        Self {
            trie: Box::new(Trie::new()),
        }
    }

    fn build_dict(&mut self, dictionary: Vec<String>) {
        for d in dictionary.into_iter() {
            self.trie.insert(&d);
        }
    }

    fn search(&self, search_word: String) -> bool {
        self.trie.search_with_exact_diff(search_word.as_bytes(), 1)
    }
}
