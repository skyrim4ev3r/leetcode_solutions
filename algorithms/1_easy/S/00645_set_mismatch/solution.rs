impl Solution {
    pub fn find_error_nums(mut nums: Vec<i32>) -> Vec<i32> {

        let mut duplicate_num = -1_i32;
        let mut missing_num = -1_i32;
        let len = nums.len();

        for i in 0..len {
            let index = nums[i].abs() as usize - 1;
            if nums[index] < 0 {
                duplicate_num = nums[i].abs();
            } else {
                nums[index] *= -1;
            }
        }

         for i in 0..len {
            if nums[i] > 0 {
                missing_num = i as i32 + 1;
                break;
            } 
        }

        vec![duplicate_num, missing_num]
    }
}
