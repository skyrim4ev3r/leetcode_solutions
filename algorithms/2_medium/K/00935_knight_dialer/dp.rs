impl Solution {
    const MOD_TO: i64 = 1_000_000_007;

    pub fn knight_dialer(n: i32) -> i32 {
        let mut dp = [0_i64; 20];
        let (mut curr, mut next) = dp.split_at_mut(10);
        next.iter_mut().for_each(|x| *x = 1);

        for _ in 1..n {
            curr[0] = (next[4] + next[6]) % Self::MOD_TO;
            curr[7] = (next[2] + next[6]) % Self::MOD_TO;
            curr[9] = (next[4] + next[2]) % Self::MOD_TO;
            curr[8] = (next[1] + next[3]) % Self::MOD_TO;
            curr[4] = (next[0] + next[9] + next[3]) % Self::MOD_TO;
            curr[6] = (next[1] + next[7] + next[0]) % Self::MOD_TO;
            curr[1] = (next[6] + next[8]) % Self::MOD_TO;
            curr[2] = (next[7] + next[9]) % Self::MOD_TO;
            curr[3] = (next[4] + next[8]) % Self::MOD_TO;
            curr[5] = 0;

            (next, curr) = (curr, next);
        }

        (next.iter().map(|x| *x).sum::<i64>() % Self::MOD_TO).try_into().unwrap()
    }
}
