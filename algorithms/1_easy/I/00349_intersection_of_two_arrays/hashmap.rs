use std::collections::HashMap;

impl Solution {
    pub fn intersection(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> Vec<i32> {
        if nums1.len() > nums2.len() {
            std::mem::swap(&mut nums1, &mut nums2);
        }

        let mut map: HashMap<i32, (bool, bool)> = HashMap::with_capacity(2 * nums1.len());

        for num in nums1.iter() {
            map.entry(*num).or_insert((true, false));
        }

        for num in nums2.iter() {
            map.entry(*num).and_modify(|x| x.1 = true);
        }

        let mut count = map.iter().filter(|&(_, &(f1, f2))| f1 && f2).count();
        let mut res = Vec::with_capacity(count);

        for (num, (f1, f2)) in map {
            if f1 && f2 {
                res.push(num);
            }
        }

        res
    }
}
