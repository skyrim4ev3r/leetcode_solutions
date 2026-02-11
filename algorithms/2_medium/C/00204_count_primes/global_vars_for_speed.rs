impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        static MAX_N: usize = 5_000_001;
        static mut SHOULD_INIT_ARRAY: bool = true;
        static mut IS_PRIME: [bool; MAX_N] = [true; MAX_N];
        static mut PREFIX_COUNT: [i32; MAX_N] = [0; MAX_N];

        unsafe {
            if SHOULD_INIT_ARRAY {
                IS_PRIME[0] = false;
                IS_PRIME[1] = false;

                let ceil_sqrt_max_n = (MAX_N as f64).sqrt().ceil() as usize;

                for i in 0..=ceil_sqrt_max_n {
                    if IS_PRIME[i] {
                        for j in ((i * 2)..MAX_N).step_by(i) {
                            IS_PRIME[j] = false;
                        }
                    }
                }

                for i in 1..MAX_N {
                    PREFIX_COUNT[i] = PREFIX_COUNT[i - 1] + if IS_PRIME[i - 1] { 1 } else { 0 };
                }

                SHOULD_INIT_ARRAY = false;
            }

            PREFIX_COUNT[n as usize]
        }        
    }
}
