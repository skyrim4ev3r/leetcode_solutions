impl Solution {
    pub fn find_duplicate(mut nums: Vec<i32>) -> i32 {

        let mut res = -1_i32;
        let mut index = 0_usize;
        let len = nums.len();

        while index < len {
            let num_as_index = (nums[index].abs() - 1) as usize;

            if nums[num_as_index] > 0 {
                nums[num_as_index] *= -1;
            } else {
                res = nums[index].abs();
                break;
            }

            index += 1;
        }

        for i in 0..index {
            let num_as_index = (nums[i].abs() - 1) as usize;
            nums[num_as_index] *= -1;
        }

        res
    }
}
