use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut fruit_count = HashMap::new();
        let mut max = 0;

        for right in 0..fruits.len() {
            *fruit_count.entry(fruits[right]).or_insert(0) += 1;

            while fruit_count.len() > 2 {
                if let Some(count) = fruit_count.get_mut(&fruits[left]) {
                    *count -= 1;
                    if *count == 0 {
                        fruit_count.remove(&fruits[left]);
                    }
                }

                left += 1;
            }

            max = max.max(right - left + 1);
        }

        max as i32
    }
}
