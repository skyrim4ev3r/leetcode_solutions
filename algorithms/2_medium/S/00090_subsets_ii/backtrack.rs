impl Solution {
    fn backtrack(
        nums: &Vec<i32>,
        res: &mut Vec<Vec<i32>>,
        temp: &mut Vec<i32>,
        curr_index: usize,
        len: usize
    ) {
        res.push(temp.clone());

        for  i in curr_index..len {
            if i > curr_index && nums[i] == nums[i - 1] {
                continue;
            }
            temp.push(nums[i]);
            Self::backtrack(nums, res, temp, i + 1, len);
            temp.pop();
        }
    }

    pub fn subsets_with_dup(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut temp: Vec<i32> = Vec::new();
        let mut res: Vec<Vec<i32>> = Vec::new();

        nums.sort_unstable();
        Self::backtrack(&nums, &mut res, &mut temp, 0, nums.len());

        res
    }
}
