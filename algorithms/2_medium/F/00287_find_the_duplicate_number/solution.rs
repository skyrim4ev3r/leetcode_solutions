impl Solution {
    pub fn find_duplicate(mut nums: Vec<i32>) -> i32 {
        debug_assert!(nums.len() > 0);
        let len = nums.len();

        for i in 0..len {
            let nums_i_as_idx = (nums[i].abs() - 1) as usize;
            debug_assert!(nums_i_as_idx < len);
            if nums[nums_i_as_idx] > 0 {
                nums[nums_i_as_idx] *= -1;
            } else {
                for j in 0..i {
                    let nums_j_as_idx = (nums[j].abs() - 1) as usize;
                    nums[nums_j_as_idx] *= -1;
                }

                return nums[i];
            }
        }

        unreachable!("Error: no duplicate found\n")
    }
}
