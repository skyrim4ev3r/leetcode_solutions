impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut order_values = [0_u8; 26];

        for (i, byte) in order.as_bytes().iter().enumerate() {
            order_values[(*byte - b'a') as usize] = i as u8;
        }

        for w in words.windows(2) {
            let bytes1 = w[0].as_bytes();
            let bytes2 = w[1].as_bytes();
            let min_len_words = bytes1.len().min(bytes2.len());
            let mut are_prefix_equal = true;

            for i in 0..min_len_words {
                let val1 = order_values[(bytes1[i] - b'a') as usize];
                let val2 = order_values[(bytes2[i] - b'a') as usize];

                match val1.cmp(&val2) {
                    std::cmp::Ordering::Greater => return false,
                    std::cmp::Ordering::Less => {
                        are_prefix_equal = false;
                        break;
                    },
                    _ => {}
                }
            }

            if are_prefix_equal && bytes1.len() > bytes2.len() {
                return false;
            }
        }

        true
    }
}
