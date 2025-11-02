impl Solution {
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();

        for i in 0..len {
            let index = nums[i].abs() as usize - 1;
            if nums[index] > 0 {
                nums[index] *= -1;
            }
        }

        let mut res: Vec<i32> = Vec::new();

        for i in 0..len {
            if nums[i] > 0 {
                res.push(i as i32 + 1);
            }
        }

        res
    }
}
