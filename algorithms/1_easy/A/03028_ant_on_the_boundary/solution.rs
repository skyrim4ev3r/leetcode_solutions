impl Solution {
    pub fn return_to_boundary_count(nums: Vec<i32>) -> i32 {
        let mut sum = 0_i32;
        let mut count = 0_i32;

        for num in nums.iter() {
            sum += *num;

            if sum == 0 {
                count += 1;
            }
        }

        count
    }
}
