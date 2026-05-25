impl Solution {
    fn fact(n: usize) -> usize {
        let mut r = 1_usize;
        for i in 2..=n { 
            r *= i;
        }
        r
    }

    fn backtrack(
        res: &mut Vec<Vec<i32>>,
        rows: usize,
        cols: usize,
        temp: &mut Vec<i32>,
        temp_index: usize,
        seen: &mut Vec<bool>,
        nums: &Vec<i32>,
    ) {
        if temp_index == cols {
            res.push(temp.clone());
            return;
        }

        for idx in 0..cols {
            if !seen[idx] {
                seen[idx] = true;
                temp[temp_index] = nums[idx];
                Self::backtrack(res, rows, cols, temp, temp_index + 1, seen, nums);
                seen[idx] = false;
            }
        }
    }

    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let cols = nums.len();
        let rows = Self::fact(cols);
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(rows);
        let mut temp = vec![0_i32; cols];
        let mut seen = vec![false; cols];
        Self::backtrack(&mut res, rows, cols, &mut temp, 0, &mut seen, &nums);

        res
    }
}
