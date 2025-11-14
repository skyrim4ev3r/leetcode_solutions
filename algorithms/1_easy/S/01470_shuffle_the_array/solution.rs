impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let n_usize = n as usize;
        let mut res: Vec<i32> = Vec::with_capacity(nums.len());

        for i in 0..n_usize {
            res.push(nums[i]);
            res.push(nums[i + n_usize]);
        }

        res
    }
}
