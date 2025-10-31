use std::collections::HashSet;

impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {

        let mut distinct_nums_set = nums.into_iter().collect::<HashSet<_>>();
        let mut distinct_nums_vec = distinct_nums_set.into_iter().collect::<Vec<_>>();

        distinct_nums_vec.sort_unstable_by(|a, b| b.cmp(&a));

        if distinct_nums_vec.len() < 3 {
            return distinct_nums_vec[0];
        }

        distinct_nums_vec[2]
    }
}
