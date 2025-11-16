impl Solution {
    pub fn missing_number(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();

        for i in 0..len {
            let num_as_index = if nums[i] < 0 {nums[i].abs() - 1} else {nums[i]} as usize;

            if num_as_index != len {
                nums[num_as_index] = -1 * nums[num_as_index] - 1;
            }
        }

        for (index, num) in nums.iter().enumerate() {
            if *num >= 0 {
                return index as i32;
            }
        }

        len as i32
    }
}
