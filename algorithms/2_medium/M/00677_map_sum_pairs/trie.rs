use std::collections::HashMap;

struct Trie {
    next: HashMap<u8, Box<Trie>>,
    val: i32,
}

impl Trie {
    fn new() -> Self {
        Self {
            next: HashMap::new(),
            val: 0,
        }
    }

    fn dfs_sum_up(&self) -> i32 {
        let mut sum = self.val;

        for (_, next) in self.next.iter() {
            sum += next.dfs_sum_up();
        }

        sum
    }

    fn insert(&mut self, key: &str, val: i32) {
        let mut curr = self;

        for &byte in key.as_bytes().iter() {
            curr = &mut *curr.next.entry(byte).or_insert(Box::new(Trie::new()));
        }

        curr.val = val;
    }

    fn find(&self, prefix: &str) -> Option<&Self> {
        let mut curr = self;

        for byte in prefix.as_bytes().iter() {
            if let Some(next) = curr.next.get(byte) {
                curr = next;
            } else {
                return None;
            }
        }

        Some(curr)
    }
}

struct MapSum {
    trie: Box<Trie>,
}

impl MapSum {
    fn new() -> Self {
        Self {
            trie: Box::new(Trie::new()),
        }
    }

    fn insert(&mut self, key: String, val: i32) {
        self.trie.insert(&key, val);
    }

    fn sum(&self, prefix: String) -> i32 {
        match self.trie.find(prefix.as_str()) {
            Some(node) => node.dfs_sum_up(),
            None => 0,
        }
    }
}
