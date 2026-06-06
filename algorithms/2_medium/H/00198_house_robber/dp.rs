impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let (mut prev_prev, mut prev, mut curr) = (0_i32, 0_i32, 0_i32);

        for num in nums.into_iter() {
            let next = num + std::cmp::max(prev, prev_prev);
            (prev_prev, prev, curr) = (prev, curr, next);
        }

        std::cmp::max(curr, prev)
    }
}
