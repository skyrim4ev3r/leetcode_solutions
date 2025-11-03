impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut max = 0_i32;
        for &num in candies.iter() {
            max = max.max(num);
        }

        let mut res: Vec<bool> = Vec::with_capacity(candies.len());
        for num in candies.into_iter() {
            if num + extra_candies >= max {
                res.push(true);
            } else {
                res.push(false);
            }
        }

        res
    }
}
