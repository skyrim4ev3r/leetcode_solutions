use std::collections::HashSet;

impl Solution {
    pub fn find_missing_elements(mut nums: Vec<i32>) -> Vec<i32> {
        let mut set: HashSet<_> = nums.iter().collect();
        let max: i32 = *nums.iter().max().unwrap();
        let min: i32 = *nums.iter().min().unwrap();
        let mut res: Vec<i32> = Vec::new();

        for val in min..max {
            if !set.contains(&val) {
                res.push(val);
            }
        }

        res
    }
}
