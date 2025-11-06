use std::collections::HashMap;

impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut hashmap: HashMap<&[u8], usize> = HashMap::new();
        let mut res: Vec<String> = Vec::new();
        let mut min_index_sum = usize::MAX;

        for (index, word) in list1.iter().enumerate() {
            hashmap.insert(word.as_bytes(), index);
        }

        for (index, word) in list2.into_iter().enumerate() {
            if index > min_index_sum {
                break;
            }

            if let Some(list1_index) = hashmap.get(word.as_bytes()) {
                if list1_index + index < min_index_sum {
                    min_index_sum = list1_index + index;
                    res.clear();
                    res.push(word);
                } else if list1_index + index == min_index_sum {
                    res.push(word);
                }
            }
        }

        res
    }
}
