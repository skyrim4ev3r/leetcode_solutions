impl Solution {
    const DIV: i64 = 1_000_000_007;

    pub fn xor_after_queries(mut nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        for query in queries.into_iter() {
            let right = query[1] as usize;
            let step = query[2] as usize;
            let v = query[3] as i64;

            for left in ((query[0] as usize)..=right).step_by(step) {
                nums[left] = ((nums[left] as i64) * v % Self::DIV) as i32;
            }
        }

        let mut res = 0_i32;

        for num in nums.into_iter() {
            res ^= num;
        }

        res
    }
}
