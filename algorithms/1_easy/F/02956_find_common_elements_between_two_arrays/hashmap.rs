use std::collections::HashMap;

impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map1: HashMap<i32, i32> = HashMap::new();
        let mut map2: HashMap<i32, i32> = HashMap::new();
        let mut count1 = 0_i32;
        let mut count2 = 0_i32;

        for &num in nums1.iter() {
            *map1.entry(num).or_insert(0) += 1;
        }

        for &num in nums2.iter() {
            *map2.entry(num).or_insert(0) += 1;
        }

        for (num1, &freq1) in map1.iter() {
            if let Some(&freq2) = map2.get(num1) {
                count1 += freq1;
                count2 += freq2;
            }
        }

        vec![count1, count2]
    }
}
