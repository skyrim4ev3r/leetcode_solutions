use std::collections::HashSet;

impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {

        let mut nums_set: HashSet<i32> = HashSet::new();
        let mut max = i32::MIN;

        for num in nums.into_iter() {
            if num > 0 {
                nums_set.insert(num);
            }
            max = max.max(num);
        }

        if nums_set.is_empty() {
            return max;
        }

        nums_set.into_iter().sum()
    }
}
