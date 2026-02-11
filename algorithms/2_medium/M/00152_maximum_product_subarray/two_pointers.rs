impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut left = 0_usize;
        let mut prod = 1_i32;
        let mut max_prod = i32::MIN;

        for right in 0..len {
            if nums[right] == 0 {
                max_prod = max_prod.max(0);
                left = right + 1;
                prod = 1;
            } else {
                prod *= nums[right];
                max_prod = max_prod.max(prod);

                if right + 1 == len || nums[right + 1] == 0 {
                    while left < right {
                        prod /= nums[left];
                        max_prod = max_prod.max(prod);
                        left += 1;
                    }
                }
            }
        }

        max_prod
    }
}
