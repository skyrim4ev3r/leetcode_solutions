impl Solution {
    pub fn rotate_elements(mut nums: Vec<i32>, mut k: i32) -> Vec<i32> {
        let nums_len = nums.len();
        let mut positive_vals = nums.iter().filter(|x| **x >= 0).map(|x| *x).collect::<Vec<i32>>();
        let positive_len = positive_vals.len();

        if positive_len == 0 {
            return nums;
        }

        k %= positive_len as i32;
        positive_vals.rotate_left(k as usize);

        let mut positive_index = 0_usize;

        for nums_index in 0..nums_len {
            if nums[nums_index] >= 0 {
                nums[nums_index] = positive_vals[positive_index];
                positive_index += 1;
            }
        }

        nums
    }
}
