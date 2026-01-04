impl Solution {
    pub fn max_operations(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let first_sum = nums[0] + nums[1];
        let mut count = 0_i32;

        for i in (0..len).step_by(2) {
            if i + 1 < len && nums[i] + nums[i + 1] == first_sum {
                count += 1;
            } else {
                break;
            }
        }

        count
    }
}
