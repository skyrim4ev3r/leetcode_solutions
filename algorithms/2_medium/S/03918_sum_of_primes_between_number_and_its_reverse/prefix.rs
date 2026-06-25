use std::sync::OnceLock;

const MAX_N: usize = 1_000;
static PRIMES: OnceLock<[i32; MAX_N + 1]> = OnceLock::new();

fn build_primes() -> [i32; MAX_N + 1] {
    let mut arr = [1_i32; MAX_N + 1];
    arr[0] = 0;
    arr[1] = 0;
    let sq = (MAX_N + 1).isqrt();
    for i in 2..=sq {
        if arr[i] == 1 {
            for j in ((i * i)..=MAX_N).into_iter().step_by(i) {
                arr[j] = 0;
            }
        }
    }

    for i in 1..=MAX_N {
        if arr[i] == 1 {
            arr[i] = i as i32;
        }

        arr[i] += arr[i - 1];
    }

    arr
}

impl Solution {
    #[inline(always)]
    fn reverse(mut n: i32) -> i32 {
        let mut rev = 0;
        while n > 0 {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        rev
    }

    pub fn sum_of_primes_in_range(n: i32) -> i32 {
        assert!(n >= 1 && n <= 1000);
        let rev = Self::reverse(n);
        let (min, max) = (rev.min(n), rev.max(n));
        let arr = PRIMES.get_or_init(build_primes);

        arr[max as usize]- arr[(min - 1) as usize]
    }
}
