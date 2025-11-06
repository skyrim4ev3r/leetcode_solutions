impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        let mut res = vec![-1; nums.len()];
        for i in 0..nums.len() {
            for ans in (nums[i] / 2)..nums[i] {
                if (ans | (ans + 1)) == nums[i] {
                    res[i] = ans;
                    break;
                }
            }
        }

        res
    }
}

