impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let nums_len = nums.len();

        if nums_len < 3 {
            return nums_len as i32;
        }

        let mut write_index = 2_usize;

        for read_index in 2..nums_len {
            if nums[read_index] == nums[write_index - 2] {
                continue;
            }

            nums[write_index] = nums[read_index];
            write_index += 1;
        }

        write_index as i32
    }
}
