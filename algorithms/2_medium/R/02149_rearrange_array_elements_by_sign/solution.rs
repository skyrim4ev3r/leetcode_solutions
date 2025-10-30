impl Solution {
    pub fn rearrange_array(mut nums: Vec<i32>) -> Vec<i32> {
        let mut index_neg = 1_usize;
        let mut index_pos = 0_usize;

        let mut res = vec![0_i32; nums.len()];

        for num in nums.into_iter() {
            if num < 0 {
                res[index_neg] = num;
                index_neg += 2;
            } else {
                res[index_pos] = num;
                index_pos += 2;
            }
        }

        res
    }
}
