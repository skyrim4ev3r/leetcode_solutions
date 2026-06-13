use std::collections::HashMap;

impl Solution {
    pub fn intersect(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> Vec<i32> {
        if nums1.len() > nums2.len() {
            std::mem::swap(&mut nums1, &mut nums2);
        }

        let mut map: HashMap<i32, (i32, i32)> = HashMap::with_capacity(2 * nums1.len());

        for num in nums1.iter() {
            map.entry(*num).and_modify(|x| x.0 += 1).or_insert((1, 0));
        }

        for num in nums2.iter() {
            map.entry(*num).and_modify(|x| x.1 += 1);
        }

        let mut count = map.iter().map(|(_, &(f1, f2))| f1.min(f2)).sum::<i32>();
        let mut res = Vec::with_capacity(count as usize);

        for (num, (f1, f2)) in map {
            let new_len = res.len() + f1.min(f2) as usize;
            res.resize(new_len, num);
        }

        res
    }
}
