use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>, nums4: Vec<i32>) -> i32 {
        let n = nums1.len();
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(n * n);
        let mut count = 0_i32;

        for i3 in 0..n {
            for i4 in 0..n {
                *hashmap.entry(nums3[i3] + nums4[i4]).or_insert(0) += 1;
            }
        }

        for i1 in 0..n {
            for i2 in 0..n {
                let sum = nums1[i1] + nums2[i2];
                let other = -sum;

                if let Some(freq) = hashmap.get(&other) {
                    count += *freq
                }
            }
        }

        count
    }
}
