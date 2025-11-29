use std::collections::HashSet;

impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let mut hashset: HashSet<i32> = HashSet::new();
        let mut count = 0_i32;

        for num in nums.iter() {
            if hashset.contains(&(*num - diff)) && hashset.contains(&(*num - (2 * diff))) {
                count += 1;
            }

            hashset.insert(*num);
        }

        count
    }
}
