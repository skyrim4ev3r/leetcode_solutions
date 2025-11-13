impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut curr_num = 0_i32;
        let mut res: Vec<bool> = Vec::with_capacity(nums.len());

        for num in nums.iter() {
            curr_num = (curr_num * 2 + num) % 5;
            res.push(curr_num == 0);
        }

        res
    }
}
