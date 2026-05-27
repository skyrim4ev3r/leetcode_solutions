impl Solution {
    fn backtrack(nums: &Vec<i32>, nums_len: usize, nums_idx: usize, res: &mut Vec<Vec<i32>>, curr_vec: &mut Vec<i32>) {
        if nums_idx == nums_len {
            res.push(curr_vec.clone());
            return;
        }

        Self::backtrack(nums, nums_len, nums_idx + 1, res, curr_vec);
        curr_vec.push(nums[nums_idx]);
        Self::backtrack(nums, nums_len, nums_idx + 1, res, curr_vec);
        curr_vec.pop();
    }

    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let nums_len = nums.len();
        let nums_idx = 0;

        let res_capacity = 1_usize << nums_len;
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(res_capacity);

        let curr_vec_capacity = nums_len;
        let mut curr_vec: Vec<i32> = Vec::with_capacity(curr_vec_capacity);

        Self::backtrack(&nums, nums_len, nums_idx, &mut res, &mut curr_vec);

        res
    }
}
