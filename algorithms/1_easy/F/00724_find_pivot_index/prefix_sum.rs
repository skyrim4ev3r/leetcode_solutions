impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {

        let len = nums.len(); 
        let mut postfix_sum: i32 = nums.iter().sum();
        let mut prefix_sum = 0_i32;

        for i in 0..len {
            if i > 0 {
                prefix_sum += nums[i - 1];
            }

            postfix_sum -= nums[i];

            if prefix_sum == postfix_sum {
                return i as i32;
            }
        }

        -1
    }
}
