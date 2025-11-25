impl Solution {
    pub fn duplicate_numbers_xor(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let len = nums.len();
        let mut res = 0_i32;

        for w in nums.windows(2) {
            if w[1] == w[0] {
                res ^= w[1];
            }
        }

        res
    }
}
