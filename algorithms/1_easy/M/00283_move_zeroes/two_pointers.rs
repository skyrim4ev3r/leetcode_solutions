impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let len = nums.len();
        let mut write_index = 0_usize;

        for read_index in 0..len {
            if nums[read_index] != 0 {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        for i in write_index..len {
            nums[i] = 0;
        }
    }
}
