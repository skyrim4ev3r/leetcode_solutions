impl Solution {
    fn subsets_recursive(nums: & Vec<i32>, res: &mut Vec<Vec<i32>>, curr_vec: &mut Vec<i32>, len: usize, start_index: usize) {
        res.push(curr_vec.clone());

        for i in start_index..len {
            curr_vec.push(nums[i]);
            Self::subsets_recursive(nums, res, curr_vec, len, i + 1);
            curr_vec.pop();
        }
    }

    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let len = nums.len();
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut tmp_vec: Vec<i32> = Vec::with_capacity(len);

        Self::subsets_recursive(& nums, &mut res, &mut tmp_vec, len, 0);

        res
    }
}
