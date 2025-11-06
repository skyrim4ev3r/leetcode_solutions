impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for num in nums.into_iter() {
            let mut p = 1_i32;
            while p <= num {
                p *= 10;
            }
            p /= 10;

            while p > 0 {
                res.push((num / p) % 10);
                p /= 10;
            }
        }

        res
    }
}
