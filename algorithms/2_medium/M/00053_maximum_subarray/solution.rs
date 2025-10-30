impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {

        let mut sum = 0_i32;
        let mut max = i32::MIN;

        for num in nums.into_iter() {
            sum += num;
            max = max.max(sum);
            // If sum be less than 0, then reset sum to 0 and start again
            sum = sum.max(0);
        }

        max
    }
}
