impl Solution {
    pub fn minimum_average(mut nums: Vec<i32>) -> f64 {
        let mut l = 0_usize;
        let mut r = nums.len() - 1;
        let mut avg_min = f64::MAX;

        nums.sort_unstable();

        while l < r {
            avg_min = avg_min.min((nums[l] + nums[r]) as f64 / 2_f64);
            r -= 1;
            l += 1;
        }

        avg_min
    }
}
