use std::collections::HashMap;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map1: HashMap<i32, i32> = HashMap::new();
        let mut map2: HashMap<i32, i32> = HashMap::new();
        let mut res: Vec<i32> = Vec::new();

        for num in nums1.iter() {
            *map1.entry(*num).or_insert(0) += 1;
        }

        for num in nums2.iter() {
            *map2.entry(*num).or_insert(0) += 1;
        }

        for (num1, count1) in map1.iter() {
            if let Some(count2) = map2.get(num1) {
                let new_len = res.len() + (*count1).min(*count2) as usize;
                res.resize(new_len, *num1);
            }
        }

        res
    }
}
