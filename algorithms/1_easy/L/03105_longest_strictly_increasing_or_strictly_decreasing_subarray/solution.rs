impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let mut longest = 1_i32;
        let mut curr = 0_i32;
        let mut state = 0_i8;

        for w in nums.windows(2) {
            if (w[1] > w[0]) {
                if (state != 1) {
                    curr = 2;
                    state = 1;
                } else {
                    curr += 1;
                }
            } else if w[1] < w[0] {
                if (state != -1) {
                    curr = 2;
                    state = -1;
                } else {
                    curr += 1;
                }
            } else {
                state = 0;
                curr = 1;
            }

            longest = longest.max(curr);
        }

        longest
    }
}
