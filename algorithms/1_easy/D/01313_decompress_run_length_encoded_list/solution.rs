impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut res: Vec<i32> = Vec::new();

        for i in (0..(len - 1)).step_by(2) {
            res.extend(std::iter::repeat(nums[i + 1]).take(nums[i] as usize));
        }

        res
    }
}
