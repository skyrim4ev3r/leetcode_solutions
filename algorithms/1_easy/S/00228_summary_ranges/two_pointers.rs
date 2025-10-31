impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let len = nums.len();

        let mut res: Vec<String> = Vec::new();

        // This 'if' is optional; the code logic can handle len of 0. 
        // It's just for clarity and early exit.
        if len == 0 {
            return res;
        }

        let mut left = 0_usize;
        let mut right = 1_usize;

        while right <= len {
            while right < len && nums[right - 1] + 1 == nums[right] {
                right += 1;
            }

            if left + 1 == right {
                res.push(nums[left].to_string());
            } else {
                res.push(format!("{}->{}", nums[left], nums[right - 1]));
            }

            left = right;
            right += 1;
        }

        res
    }
}
