impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {

        let len = nums.len();
        let mut write_index = 0_usize;

        for read_index in 0..len {
            if nums[read_index] != val {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        write_index as i32
    }
}
