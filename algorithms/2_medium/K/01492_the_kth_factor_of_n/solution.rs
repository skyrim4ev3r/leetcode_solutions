impl Solution {
    pub fn kth_factor(n: i32, mut k: i32) -> i32 {
        let sqrt_n = n.isqrt();
        let mut rest_factors: Vec<i32> = Vec::new();

        for i in 1..=sqrt_n {
            if n % i == 0 {
                k -= 1;
                if k == 0 {
                    return i;
                }

                let other = n / i;
                if i != other {
                    rest_factors.push(other);
                }
            }
        }

        let len_rest_factors = rest_factors.len();
        if len_rest_factors < k as usize {
            return -1;
        }

        rest_factors[len_rest_factors - (k as usize)]
    }
}
