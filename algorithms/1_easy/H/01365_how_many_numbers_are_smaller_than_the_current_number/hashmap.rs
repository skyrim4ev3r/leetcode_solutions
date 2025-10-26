use std::collections::HashMap;

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {

        let len = nums.len();
        let mut sorted_nums = nums.clone();

        sorted_nums.sort_unstable();

        let mut counts: HashMap<i32, i32> = HashMap::new();

        for i in 0..len {
            if i > 0 && sorted_nums[i] == sorted_nums[i - 1] {
                    continue;
            }

            counts.insert(sorted_nums[i], i as i32);
        }

        let mut res: Vec<i32> = Vec::with_capacity(len);

        for num in nums.into_iter() {
            res.push(counts[&num]);
        }

        res
    }
}
