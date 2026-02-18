use std::collections::HashSet;

impl Solution {
    fn backtrack(
        nums: &Vec<i32>,
        res: &mut Vec<Vec<i32>>,
        temp: &mut Vec<i32>,
        curr_index: usize,
        len: usize,
    ) {
        if curr_index == len {
            if temp.len() > 1 {
                res.push(temp.clone());
            }

            return;
        }

        if temp.is_empty() || *temp.last().unwrap() <= nums[curr_index] {
            temp.push(nums[curr_index]);
            Self::backtrack(nums, res, temp, curr_index + 1, len);
            temp.pop();
        }

        if temp.is_empty() || *temp.last().unwrap() != nums[curr_index] {
            Self::backtrack(nums, res, temp, curr_index + 1, len);
        }
    }

    pub fn find_subsequences(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let len = nums.len();
        let mut temp: Vec<i32> = Vec::new();
        let mut res: Vec<Vec<i32>> = Vec::new();

        Self::backtrack(&nums, &mut res, &mut temp, 0, len);

        res
    }
}
