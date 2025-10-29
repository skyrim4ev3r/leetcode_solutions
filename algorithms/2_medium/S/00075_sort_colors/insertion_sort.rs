impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let len = nums.len();

        for i in 0..len {
            let mut curr_index = i;

            while curr_index > 0 && nums[curr_index - 1] > nums [curr_index] {
                let tmp = nums[curr_index];
                nums[curr_index] = nums[curr_index - 1];
                nums[curr_index - 1] = tmp;
                curr_index -= 1;
            }
        }
    }
}
