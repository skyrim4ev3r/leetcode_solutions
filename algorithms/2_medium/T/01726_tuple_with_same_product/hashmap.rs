use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        let len = nums.len();

        for i in 0..len {
            for j in (i + 1)..len {
                *hashmap.entry(nums[i] * nums[j]).or_insert(0) += 1;
            }
        }

        let mut res = 0_i32;

        for (_, freq) in hashmap.into_iter() {
            res += ((freq * (freq - 1)) / 2) * 8;
        }

        res
    }
}
