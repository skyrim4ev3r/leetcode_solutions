impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {

        let len = nums.len();
        let mut left = 0_usize;
        let mut right = 0_usize;
        let mut count = 0_i32;

        while right < len - 1 {
            let mut max_jump = 0_usize;

            for i in left..=right {
                max_jump = max_jump.max(i + nums[i] as usize);
            }

            left = right + 1;
            right = max_jump;
            count += 1;
        }

        count
    }
}
