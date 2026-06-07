use std::sync::LazyLock;

const MAX_INPUT: usize = 5 * 10_usize.pow(6) + 1;

#[inline(always)]
fn init_prefix_primes() -> Box::<[i32]> {
    let mut is_prime = vec![1_i32; MAX_INPUT].into_boxed_slice();
    is_prime[0] = 0;
    is_prime[1] = 0;

    let ceil_sqrt_max_n = (MAX_INPUT as f64).sqrt().ceil() as usize;

    for i in 0..=ceil_sqrt_max_n {
        if is_prime[i] == 1 {
            for j in ((i * i)..MAX_INPUT).step_by(i) {
                is_prime[j] = 0;
            }
        }
    }

    let mut prev_is_prime =  0;

    for i in 1..MAX_INPUT {
        let curr_is_prime = is_prime[i];
        is_prime[i] = is_prime[i - 1] + prev_is_prime;
        prev_is_prime = curr_is_prime;
    }

    is_prime
}

impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        static PREFIX_PRIMES: LazyLock<Box<[i32]>> = LazyLock::new(|| init_prefix_primes());
        PREFIX_PRIMES[n as usize]
    }
}
