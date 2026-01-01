impl Solution {
    pub fn has_trailing_zeros(nums: Vec<i32>) -> bool {
        let mut even_count = 0_i32;

        for &num in nums.iter() {
            if (num & 1) == 0 {
                even_count += 1;

                if even_count > 1 {
                    return true;
                }
            }
        }

        false
    }
}
