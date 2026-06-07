use std::sync::Once;

const MAX_INPUT: usize = 5 * 10_usize.pow(6) + 1;
static INIT_PREFIX_PRIMES: Once = Once::new();
static mut PREFIX_PRIMES: [i32; MAX_INPUT] = [1_i32; MAX_INPUT];

fn init_prefix_primes() {
    unsafe {
        PREFIX_PRIMES[0] = 0;
        PREFIX_PRIMES[1] = 0;

        let ceil_sqrt_max_n = (MAX_INPUT as f64).sqrt().ceil() as usize;

        for i in 0..=ceil_sqrt_max_n {
            if PREFIX_PRIMES[i] == 1 {
                for j in ((i * i)..MAX_INPUT).step_by(i) {
                    PREFIX_PRIMES[j] = 0;
                }
            }
        }

        let mut prev_is_prime =  0;

        for i in 1..MAX_INPUT {
            let curr_is_prime = PREFIX_PRIMES[i];
            PREFIX_PRIMES[i] = PREFIX_PRIMES[i - 1] + prev_is_prime;
            prev_is_prime = curr_is_prime;
        }
    }
}

impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        INIT_PREFIX_PRIMES.call_once(|| init_prefix_primes());
        unsafe { PREFIX_PRIMES[n as usize] }
    }
}
