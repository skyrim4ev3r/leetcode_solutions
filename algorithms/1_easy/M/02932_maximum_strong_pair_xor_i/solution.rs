impl Solution {
    pub fn maximum_strong_pair_xor(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        let len = nums.len();

        for i in 0..len {
            for j in (i + 1)..len {
                if (nums[i] - nums[j]).abs() <= nums[i].min(nums[j]) {
                    max = max.max(nums[i] ^ nums[j]);
                }
            }
        }

        max
    }
}
