use std::cmp::Ordering;

impl Solution {
    pub fn find_closest_number(nums: Vec<i32>) -> i32 {
        let mut res = i32::MAX;

        for num in nums.into_iter() {
            match num.abs().cmp(&res.abs()) {
                Ordering::Greater => {},
                Ordering::Equal => res = res.max(num),
                Ordering::Less => res = num,
            }
        }

        res
    }
}
