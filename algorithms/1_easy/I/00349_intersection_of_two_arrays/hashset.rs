use std::collections::HashSet;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut set1: HashSet<i32> = nums1.iter().map(|x| *x).collect::<HashSet<i32>>();
        let mut set2: HashSet<i32> = nums2.iter().map(|x| *x).collect::<HashSet<i32>>();
        let mut res: Vec<i32> = Vec::new();

        for num in set1.iter() {
            if set2.contains(num) {
                res.push(*num);
            }
        }

        res
    }
}
