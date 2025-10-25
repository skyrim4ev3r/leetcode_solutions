impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {

        let nums_len = nums.len();
        let mut write_index = 1_usize;

        for read_index in 1..nums_len {
            if nums[read_index] != nums[read_index - 1] {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        write_index as i32
    }
}
