impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {

        let mut max = 0_i32;
        let mut curr = 0_i32;

        for num in nums.into_iter() {
            if num == 1 {
                curr += 1;
                max = max.max(curr);
            } else {
                curr = 0;
            }
        }

        max
    }
}
