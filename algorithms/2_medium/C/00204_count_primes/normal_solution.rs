impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        if n < 3 {
            return 0;
        }

        let n_usize = n as usize;
        let mut is_prime = vec![true; n_usize];
        let ceil_sqrt_n = (n_usize as f64).sqrt().ceil() as usize;

        is_prime[0] = false;
        is_prime[1] = false;

        for i in 0..=ceil_sqrt_n {
            if is_prime[i] {
                for j in ((i * 2)..n_usize).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }

        is_prime.into_iter().filter(|x| *x == true).count() as i32
    }
}
