impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {

        let mut max = 1_i32;
        let mut curr = 1_i32;
        let len = nums.len();

        for i in 1..len {
            if nums[i] > nums[i - 1] {
                curr += 1;
                max = max.max(curr);
            } else {
                curr = 1;
            }
        }

        max
    }
}
