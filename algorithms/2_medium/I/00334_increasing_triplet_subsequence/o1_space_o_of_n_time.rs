impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut mid_val = i32::MAX;
        let mut min_val = i32::MAX;

        for curr_val in nums {
            if curr_val > mid_val {
                return true;
            }

            if curr_val < min_val {
                min_val = curr_val;
            } else if curr_val > min_val && curr_val < mid_val {
                mid_val = curr_val;
            }
        }

        false
    }
}
