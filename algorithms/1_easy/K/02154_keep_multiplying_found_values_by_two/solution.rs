use std::collections::HashSet;

impl Solution {
    pub fn find_final_value(nums: Vec<i32>, mut original: i32) -> i32 {
        let exact = nums.iter().map(|x| *x).collect::<HashSet<i32>>();

        while exact.contains(&original) {
            original *= 2;
        }

        original
    }
}
