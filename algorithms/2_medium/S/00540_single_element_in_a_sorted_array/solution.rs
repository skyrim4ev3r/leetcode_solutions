impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let len = nums.len();

        for i in (0..(len - 1)).step_by(2) {
            if nums[i] != nums[i + 1] {
                return nums[i];
            }
        }

        nums[len - 1]
    }
}
