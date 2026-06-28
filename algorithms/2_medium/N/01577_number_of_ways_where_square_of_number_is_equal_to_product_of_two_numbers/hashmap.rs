use std::collections::HashMap;

impl Solution {
    #[inline(always)]
    fn count_pairs(nums1: &[i32], nums2: &[i32]) -> i32 {
        let len = nums1.len();
        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut res = 0;

        for &num in nums1 {
            *map.entry(num).or_insert(0) += 1;
        }

        for &num in nums2 {
            let sq = (num as i64) * (num as i64);

            for (&val, &freq) in map.iter() {
                if sq % (val as i64) == 0 {
                    let other = (sq / (val as i64)) as i32;
                    if other == val {
                        res += freq * (freq - 1) / 2; 
                    } else if other > val {
                        if let Some(&other_freq) = map.get(&other) {
                            res += freq * other_freq;
                        }
                    }
                }
            }
        }

        res
    }

    pub fn num_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        Self::count_pairs(&nums1, &nums2) + Self::count_pairs(&nums2, &nums1)
    }
}
