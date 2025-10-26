impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {

        let mut prev_valid_min = i32::MAX;
        let mut curr_min = i32::MAX;

        for num in nums.into_iter() {
            if num > prev_valid_min {
                return true;
            }

            if num > curr_min {
                prev_valid_min = prev_valid_min.min(num);
            } else {
                curr_min = num;
            }
        }

        false
    }
}
