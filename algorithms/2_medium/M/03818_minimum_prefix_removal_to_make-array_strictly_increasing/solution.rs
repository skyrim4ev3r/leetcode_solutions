impl Solution {
    pub fn minimum_prefix_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();

        if len <= 1 {
            return 0;
        }

        let mut index = len - 1;

        while index > 0 && nums[index] > nums[index - 1] {
            index -= 1;
        }

        index as i32
    }
}
