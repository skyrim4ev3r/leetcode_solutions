use std::collections::HashSet;

impl Solution {
    pub fn count_distinct_integers(nums: Vec<i32>) -> i32 {
        let mut nums_set: HashSet<i32> = HashSet::new();

        for mut num in nums.into_iter() {
            nums_set.insert(num);
            let mut rev_num = 0;
            while num > 0 {
                rev_num *= 10;
                rev_num += num % 10;
                num /= 10;
            }
            nums_set.insert(rev_num);
        }
    
        nums_set.len() as i32
    }
}
