use std::collections::HashMap;

impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {

        let mut map: HashMap<i32, u8> = HashMap::new();
        let mut res: Vec<i32> = Vec::new();

        for num in nums1.into_iter() {
            *map.entry(num).or_insert(0) |= 1;
        }

        for num in nums2.into_iter() {
            *map.entry(num).or_insert(0) |= 2;
        }

        for num in nums3.into_iter() {
            *map.entry(num).or_insert(0) |= 4;
        }

        for (key, val) in map.into_iter() {
            if val.count_ones() > 1 {
                res.push(key);
            }
        }

        res
    }
}
