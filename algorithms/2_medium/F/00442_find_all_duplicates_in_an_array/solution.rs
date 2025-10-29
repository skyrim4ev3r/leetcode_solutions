impl Solution {
    pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {

        let mut res: Vec<i32> = Vec::new();
        let len = nums.len();

        for i in 0..len {
            let num_as_index = (nums[i].abs() -1) as usize;

            if nums[num_as_index] < 0 {
                res.push(nums[i].abs());
            } else {
                nums[num_as_index] *= -1;
            }
        }

        res
    }
}
