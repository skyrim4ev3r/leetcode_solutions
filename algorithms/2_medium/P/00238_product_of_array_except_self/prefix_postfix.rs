impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        
        let nums_len = nums.len();
        let mut res = vec![0_i32; nums_len];

        let mut prefix_product = 1_i32;
        for i in 0..nums_len {
            res[i] = prefix_product;
            prefix_product *= nums[i];
        }

        let mut postfix_product = 1_i32;
        for i in (0..nums_len).rev() {
            res[i] *= postfix_product;
            postfix_product *= nums[i];
        }

        res
    }
}
