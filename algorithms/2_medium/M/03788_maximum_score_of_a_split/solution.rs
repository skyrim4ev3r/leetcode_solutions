impl Solution {
    pub fn maximum_score(nums: Vec<i32>) -> i64 {
        let len = nums.len();
        let mut min_suffix = vec![0_i32; len];
        min_suffix[len - 1] = nums[len - 1];

        for i in (0..=(len - 2)).rev() {
            min_suffix[i] = min_suffix[i + 1].min(nums[i]);
        }

        let mut prefix = 0_i64;
        let mut max_score = i64::MIN;

        for i in 0..(len - 1) {
            prefix += nums[i] as i64;
            max_score = max_score.max(prefix - min_suffix[i + 1] as i64);
        }

        max_score
    }
}
