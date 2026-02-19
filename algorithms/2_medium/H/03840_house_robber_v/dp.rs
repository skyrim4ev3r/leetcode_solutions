impl Solution {
    pub fn rob(nums: Vec<i32>, colors: Vec<i32>) -> i64 {
        struct AmountColor(i64, i32);
        let len = nums.len();
        let mut prev = AmountColor(0_i64, 0_i32);
        let mut prev_prev = AmountColor(0_i64, 0_i32);

        for i in 0..len {
            let curr = {
                let amount_to_add = if colors[i] == prev.1 { 
                    prev_prev.0
                } else {
                    prev.0.max(prev_prev.0)
                };

                AmountColor(amount_to_add + nums[i] as i64, colors[i])
            };

            (prev_prev, prev) = (if prev_prev.0 < prev.0 { prev } else { prev_prev }, curr);
        }

        prev.0.max(prev_prev.0)
    }
}
