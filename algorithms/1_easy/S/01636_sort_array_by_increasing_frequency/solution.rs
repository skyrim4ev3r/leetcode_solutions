use std::collections::HashMap;

impl Solution {
    pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32> {

        let mut res: Vec<i32> = Vec::with_capacity(nums.len());
        let mut map: HashMap<i32, u8> = HashMap::new();

        for num in nums.into_iter() {
            *map.entry(num).or_insert(0) += 1;
        }

        let mut map_vec: Vec<_> = map.into_iter().collect();
        map_vec.sort_unstable_by(|a, b| {
            if a.1 == b.1 {
                b.0.cmp(&a.0)
            } else {
                a.1.cmp(&b.1)
            }
        });

        for (num, count) in map_vec.into_iter() {
            for _ in 0..count {
                res.push(num);
            }
        }

        res
    }
}
