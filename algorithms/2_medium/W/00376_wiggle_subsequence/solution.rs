impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if (len <= 1) { return len as i32; }

        let mut cnt = 1_i32;
        let mut dir = 0_i32;

        for i in 1..len {
            if nums[i] > nums[i - 1] && dir != 1 {
                dir = 1;
                cnt += 1;
            }

            if nums[i] < nums[i - 1] && dir != -1 {
                dir = -1;
                cnt += 1;
            }
        }

        cnt
    }
}
