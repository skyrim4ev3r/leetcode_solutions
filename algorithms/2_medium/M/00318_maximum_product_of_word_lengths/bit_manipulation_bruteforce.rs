impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        let len = words.len();
        let mut masks = vec![0_u32; len];

        for i in 0..len {
            let mut mask = 0_u32;

            for &byte in words[i].as_bytes().iter() {
                mask = mask | (1 << (byte - b'a'));
            }

            masks[i] = mask;
        }

        let mut max_product_len = 0_usize;

        for i in 0..len {
            for j in (i + 1)..len {
                if (masks[i] & masks[j]) == 0 {
                    max_product_len = max_product_len.max(words[i].len() * words[j].len());
                }
            }
        }

        max_product_len as i32
    }
}
