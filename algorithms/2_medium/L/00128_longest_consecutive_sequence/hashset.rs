use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let uniques: HashSet<_> = nums.into_iter().collect();
        let mut max = 0_i32;

        for num in uniques.iter() {
            if !uniques.contains(&(num - 1)) {
                let mut right = *num;

                while uniques.contains(&(right + 1)) {
                    right += 1;
                }

                max = max.max(right - num + 1);
            }
        }

        max
    }
}
