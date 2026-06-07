#[derive(Clone, Default)]
struct TrieNode {
    is_end_of_word: bool,
    children: [u16; TrieNode::CHILDREN_LEN],
}

impl TrieNode {
    const CHILDREN_LEN: usize =  26;
}

struct Trie {
    arena: Vec<TrieNode>,
}

impl Trie {
    fn new() -> Self {
        Self {
            arena: vec![TrieNode::default()],
        }
    }

    fn insert(&mut self, word: String) {
        let mut curr = 0_usize;

        for byte in word.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < TrieNode::CHILDREN_LEN);

            if self.arena[curr].children[child_idx] == 0 {
                self.arena.push(TrieNode::default());
                debug_assert!(self.arena.len() - 1 <= u16::MAX as usize);
                self.arena[curr].children[child_idx] = (self.arena.len() - 1) as u16;
            }

            curr = self.arena[curr].children[child_idx] as usize;
        }

        self.arena[curr].is_end_of_word = true;
    }

    fn search(&self, word: String) -> bool {
        let mut curr = 0;

        for byte in word.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < TrieNode::CHILDREN_LEN);
            curr = self.arena[curr].children[child_idx] as usize;

            if curr == 0 {
                return false;
            }
        }

        self.arena[curr].is_end_of_word
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut curr = 0_usize;

        for byte in prefix.as_bytes() {
            let child_idx = (byte - b'a') as usize;
            debug_assert!(child_idx < TrieNode::CHILDREN_LEN);
            curr = self.arena[curr].children[child_idx] as usize;

            if curr == 0 {
                return false;
            }
        }

        true
    }
}
