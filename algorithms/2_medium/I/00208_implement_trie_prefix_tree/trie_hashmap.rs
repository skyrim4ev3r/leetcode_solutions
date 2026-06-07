use std::collections::HashMap;

struct Trie {
    is_end_of_word: bool,
    trie: HashMap<u8, Trie>,
}

impl Trie {

    fn new() -> Self {
        Self {
            is_end_of_word: false,
            trie: HashMap::new(),
        }
    }
    
    fn insert(&mut self, word: String) {
        let mut curr = self;
        for byte in word.as_bytes().iter() {
            curr = curr.trie.entry(*byte).or_insert(Self {
                is_end_of_word: false,
                trie: HashMap::new(),
            });
        }

        curr.is_end_of_word = true;
    }
    
    fn search(&self, word: String) -> bool {
        let mut curr = self;
        for byte in word.as_bytes().iter() {
            match curr.trie.get(byte) {
                Some(node) => curr = node,
                None => return false,
            }
        }

        curr.is_end_of_word
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut curr = self;
        for byte in prefix.as_bytes().iter() {
            match curr.trie.get(byte) {
                Some(node) => curr = node,
                None => return false,
            }
        }

        true
    }
}
