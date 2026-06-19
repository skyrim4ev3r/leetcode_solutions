impl Solution {
    fn backtrack(i: u32, n: u32, seen: u32, memo: &mut [i32]) -> i32 {
        if i > n {
            return 1;
        }

        if memo[seen as usize] != -1 {
            return memo[seen as usize];
        } 

        let mut res = 0_i32;
        for curr in 1..=n {
            let mask = 1_u32 << curr;
            if (seen & mask) == 0 && (curr % i == 0 || i % curr == 0) {
                res += Self::backtrack(i + 1, n, seen | mask, memo);
            }
        }

        memo[seen as usize] = res;
        res
    }

    pub fn count_arrangement(n_i32: i32) -> i32 {
        assert!(n_i32 >= 1 && n_i32 <= 15);
        let n = n_i32 as u32;
        let mut memo = vec![-1; (1_u32 << (n + 1)) as usize];
        let seen = 0;

        Self::backtrack(1, n , seen, &mut memo)
    }
}
