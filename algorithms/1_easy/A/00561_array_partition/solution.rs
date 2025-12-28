impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut res = 0_i32;

        nums.sort_unstable();

        for i in (0..len).step_by(2) {
            res += nums[i];
        }

        res
    }
}
