impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for mut num in nums.into_iter() {
            let mut tmp_vec: Vec<i32> = Vec::new();
            while num > 0 {
                tmp_vec.push(num % 10);
                num /= 10;
            }
            res.extend(tmp_vec.into_iter().rev());
        }

        res
    }
}
