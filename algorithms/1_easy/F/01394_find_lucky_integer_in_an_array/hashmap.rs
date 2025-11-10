use std::collections::HashMap;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut map: HashMap<i32, i32> = HashMap::new();

        for num in arr.into_iter() {
            *map.entry(num).or_insert(0) += 1;
        }

        let mut max_lucky = -1_i32;
        for (key, val) in map.into_iter() {
            if key == val {
                max_lucky = max_lucky.max(val);
            }
        }

        max_lucky
    }
}
