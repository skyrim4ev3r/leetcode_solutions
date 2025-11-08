use std::collections::HashSet;
impl Solution {
    pub fn smallest_absent(mut nums: Vec<i32>) -> i32 {
        let avg = nums.iter().sum::<i32>() / nums.len() as i32;
        let mut set: HashSet<i32> = HashSet::new();

        set.extend(nums.iter().filter(|&&x| x > avg && x > 0));

        let mut res = 1.max(avg + 1);
        while set.contains(&res) {
            res += 1;
        }

        res
    }
}
