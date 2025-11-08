impl Solution {
    pub fn alternating_sum(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut flip_flop = true;

        for num in nums.into_iter() {
            if flip_flop {
                sum += num;
            } else {
                sum -= num;
            }

            flip_flop = !flip_flop;
        }

        sum
    }
}
