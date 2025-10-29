impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {

        let len = nums.len();
        let mut left = 0_usize;
        let mut right = 0_usize;
        
        while right < len - 1 {
            let mut max_jump = 0_usize;
            for i in left..=right {
                max_jump = max_jump.max(i + nums[i] as usize);
            }

            if max_jump == right {
                return false;
            }

            left = right + 1;
            right = max_jump;
        }

        true
    }
}
