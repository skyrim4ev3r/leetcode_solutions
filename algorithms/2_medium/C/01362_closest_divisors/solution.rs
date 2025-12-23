impl Solution {
    pub fn closest_divisors(num: i32) -> Vec<i32> {
        let sqrt = (num + 2).isqrt();
        for i in (1..=sqrt).rev() {
            if (num + 1) % i == 0 {
                return vec![i, (num + 1) / i];
            }

            if (num + 2) % i == 0 {
                return vec![i, (num + 2) / i];
            }
        }

        unreachable!()
    }
}
