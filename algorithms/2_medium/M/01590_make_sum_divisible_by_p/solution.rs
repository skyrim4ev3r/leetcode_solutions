use std::collections::HashMap;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let sum = nums.iter().map(|x| *x as i64).sum::<i64>();
        let rem = (sum % p as i64) as i32;

        if rem == 0 {
            return 0;
        }

        let complement_rem = p - rem;
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        hashmap.insert(0 , -1); 

        let mut curr_rem = 0_i32;
        let mut min_eleme_to_remove = nums.len() as i32;

        for (i, num) in nums.iter().enumerate() {
            curr_rem = (curr_rem + *num) % p;

            let target_rem = (curr_rem + complement_rem) % p;

            if let Some(val) = hashmap.get(&target_rem) {
                min_eleme_to_remove = min_eleme_to_remove.min(i as i32 - *val);
            }

            hashmap.insert(curr_rem, i as i32);
        }

        if min_eleme_to_remove == nums.len() as i32 {-1} else {min_eleme_to_remove}
    }
}
