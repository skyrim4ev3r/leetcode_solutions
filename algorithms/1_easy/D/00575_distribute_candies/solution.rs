use std::collections::HashSet;

impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        ((candy_type.len() / 2).min(candy_type.iter().map(|x| *x).collect::<HashSet<i32>>().len())) as i32
    }
}
