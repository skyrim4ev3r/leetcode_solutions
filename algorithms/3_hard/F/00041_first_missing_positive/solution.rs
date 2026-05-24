impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();

        for num in nums.iter_mut() {
            if *num <= 0 {
                *num = i32::MAX;
            }
        }

        for i in 0..len {
            let num_index = (nums[i].abs() - 1) as usize;
            if num_index < len && nums[num_index] > 0 {
                nums[num_index] *= -1;
            }
        }

        for i in 0..len {
            if nums[i] > 0 {
                return i as i32 + 1;
            }
        }

        len as i32 + 1
    }
}

