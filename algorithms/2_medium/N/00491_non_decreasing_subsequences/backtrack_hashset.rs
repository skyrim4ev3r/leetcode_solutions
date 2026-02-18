use std::collections::HashSet;

impl Solution {
    fn backtrack(
        nums: &Vec<i32>,
        res: &mut Vec<Vec<i32>>,
        temp: &mut Vec<i32>,
        curr_index: usize,
        len: usize,
    ) {
        let mut visited: HashSet<i32> = HashSet::new();
        for i in curr_index..len {
            if (temp.is_empty() || nums[i] >= *temp.last().unwrap()) && visited.insert(nums[i]) {
                temp.push(nums[i]);
                if temp.len() > 1 {
                    res.push(temp.clone());
                }
                Self::backtrack(nums, res, temp, i + 1, len);
                temp.pop();
            }
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
