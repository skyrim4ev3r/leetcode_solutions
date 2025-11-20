impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut min_diff = -1_i32;

        for i in 0..len {
            for j in (i + 1)..len {
                for k in (j + 1)..len {
                    if nums[i] == nums[j] && nums[j] == nums[k] {
                        let curr_diff = ((k - i) * 2) as i32;

                        if min_diff == -1 || curr_diff < min_diff {
                            min_diff = curr_diff;
                        }
                    }
                }
            }
        }

        min_diff
    }
}
