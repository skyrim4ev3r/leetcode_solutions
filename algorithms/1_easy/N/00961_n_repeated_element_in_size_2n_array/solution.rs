impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        for w in nums.windows(3) {
            if w[0] == w[1] || w[0] == w[2] {
                return w[0];
            }

            if w[1] == w[2] {
                return w[1];
            }
        }

        if nums[0] == *nums.last().unwrap() {
            nums[0]
        } else {
            -1
        }
    }
}
