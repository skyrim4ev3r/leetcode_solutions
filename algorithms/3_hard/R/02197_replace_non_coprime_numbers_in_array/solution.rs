//use num::integer::{gcd, lcm};
impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a.abs()
        } else {
            Self::gcd(b, a % b)
        }
    }

    fn lcm(a: i32, b: i32) -> i32 {
        // here a and b are always greater than 1, otherwise should be check for div by 0
        (a / Self::gcd(a, b)) * b
    }

    pub fn replace_non_coprimes(nums: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for mut num in nums.into_iter() {
            while let Some(&last) = res.last() {
                if Self::gcd(num, last) > 1 {
                    num =  Self::lcm(num, last);
                    res.pop();
                } else {
                    break;
                }
            }

            res.push(num);
        }

        res
    }
}
