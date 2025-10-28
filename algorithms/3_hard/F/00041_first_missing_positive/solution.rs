impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {

        let n = nums.len();

        for num in nums.iter_mut() {
            if *num <= 0 {
                *num = i32::MAX;
            }
        }

        for i in 0..n {
            let num_as_index = (nums[i].abs() - 1) as usize;
            if num_as_index < n {
                if nums[num_as_index] > 0 {
                    nums[num_as_index] *= -1;
                }
            }
        }

        for i in 0..n {
            if nums[i] > 0 {
                return i as i32 + 1;
            }
        }

        n as i32 + 1
    }
}
