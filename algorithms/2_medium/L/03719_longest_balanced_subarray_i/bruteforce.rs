use std::collections::HashSet;

impl Solution {
    pub fn longest_balanced(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut longest = 0_usize;

        for i in 0..len {
            let mut evens: HashSet<i32> = HashSet::new();
            let mut odds: HashSet<i32> = HashSet::new();

            for j in i..len {
                if (nums[j] & 1) == 0 {
                    odds.insert(nums[j]);
                } else {
                    evens.insert(nums[j]);
                }

                if odds.len() == evens.len() {
                    longest = longest.max(j - i + 1);
                }
            }
        }

        longest as i32
    }
}
