impl Solution {
    pub fn transform_array(mut nums: Vec<i32>) -> Vec<i32> {
        let mut even_count = 0usize;
        for &num in & nums {
            if (num & 1) == 0 {
                even_count += 1;
            }
        }

        for i in 0..nums.len() {
            if i < even_count {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }

        nums
    }
}
