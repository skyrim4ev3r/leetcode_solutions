impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a % b)
        }
    }

    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut min = i32::MAX;
        let mut max = i32::MIN;

        for num in nums.iter() {
            min = min.min(*num);
            max = max.max(*num);
        }

        Self::gcd(max, min)
    }
}
