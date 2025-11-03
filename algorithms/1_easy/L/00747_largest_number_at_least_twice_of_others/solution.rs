impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {

        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;
        let mut max1_index = usize::MAX;
        let nums_len = nums.len();

        for i in 0..nums_len {
            if nums[i] >= max1 {
                max2 = max1;
                max1 = nums[i];
                max1_index = i;
            } else if nums[i] >= max2 {
                max2 = nums[i];
            }
        }

        if max2 * 2 <= max1 {
            return max1_index as i32
        }

        -1
    }
}
