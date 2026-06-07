#[derive(Clone)]
struct Trie {
    is_end_of_word: bool,
    children: [Option<Box<Trie>>; Self::CHILDREN_LEN],
}

impl Trie {
    const CHILDREN_LEN: usize =  26;

    fn new() -> Self {
        Self {
            is_end_of_word: false,
            children: [const { None }; 26],
        }
    }

    fn insert(&mut self, word: String) {
        let mut curr = self;

        for byte in word.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < Trie::CHILDREN_LEN);
            curr = curr.children[child_idx].get_or_insert(Box::new(Trie::new()));
        }

        curr.is_end_of_word = true;
    }

    fn search(&self, word: String) -> bool {
        let mut curr = self;

        for byte in word.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < Trie::CHILDREN_LEN);

            match &curr.children[child_idx] {
                Some(node) => curr = node,
                None => return false,
            };
        }

        curr.is_end_of_word
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut curr = self;

        for byte in prefix.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < Trie::CHILDREN_LEN);

            match &curr.children[child_idx] {
                Some(node) => curr = node,
                None => return false,
            };
        }

        true
    }
}
