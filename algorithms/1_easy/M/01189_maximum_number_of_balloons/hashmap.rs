use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let word: &[u8] = b"balloon";
        let mut hashmap: HashMap<u8, (i32, i32)> = HashMap::new();

        for byte in word.iter() {
            hashmap.entry(*byte).or_insert((0, 0)).0 += 1;
        }

        for byte in text.into_bytes().into_iter() {
            if let Some(mut val) = hashmap.get_mut(&byte) {
                val.1 += 1;
            }
        }

        hashmap.into_iter().map(|(_,t)| t.1 / t.0).min().unwrap()
    }
}
