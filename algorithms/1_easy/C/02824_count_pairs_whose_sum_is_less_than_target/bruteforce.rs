impl Solution {
    pub fn count_pairs(nums: Vec<i32>, target: i32) -> i32 {
        let mut count = 0_i32;
        let len = nums.len();

        for i in 0..len {
            for j in (i + 1)..len {
                if nums[i] + nums[j] < target {
                    count += 1;
                }
            }
        }

        count
    }
}
