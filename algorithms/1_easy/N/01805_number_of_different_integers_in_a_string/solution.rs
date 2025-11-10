use std::collections::HashSet;

impl Solution {
    pub fn num_different_integers(word: String) -> i32 {
        let mut num_chars: Vec<u8> = Vec::new();
        let mut is_seen_new_num = false;
        let mut is_seen_zero = false;

        let mut nums_chars: HashSet<Vec<u8>> = HashSet::new();

        for ch in word.into_bytes().into_iter() {
            if (ch > b'0' && ch <= b'9') || (ch == b'0' && is_seen_new_num) {
                num_chars.push(ch);
                is_seen_new_num = true;
                is_seen_zero = false;
            } else if ch == b'0' && !is_seen_new_num {
                is_seen_zero = true;
            } else {
                if is_seen_new_num {
                    is_seen_new_num = false;
                    nums_chars.insert(num_chars);
                    num_chars = Vec::new()
                } else if (is_seen_zero) {
                    nums_chars.insert(vec![b'0']);
                }
            }
        }

        if (is_seen_new_num) {
            nums_chars.insert(num_chars);
        } else if (is_seen_zero) {
            nums_chars.insert(vec![b'0']);
        }

        nums_chars.len() as i32
    }
}
