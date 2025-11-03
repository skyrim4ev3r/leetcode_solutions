use std::collections::HashSet;

impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let set1 = nums1.into_iter().collect::<HashSet<i32>>();
        let set2 = nums2.into_iter().collect::<HashSet<i32>>();

        let mut v1: Vec<i32> = Vec::new();
        let mut v2: Vec<i32> = Vec::new();

        for num in set1.iter() {
            if !set2.contains(num) {
                v1.push(*num);
            }
        }

        for num in set2.iter() {
            if !set1.contains(num) {
                v2.push(*num);
            }
        }

        res.push(v1);
        res.push(v2);

        res
    }
}
