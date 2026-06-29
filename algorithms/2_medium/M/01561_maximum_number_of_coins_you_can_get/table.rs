impl Solution {
    const MAX_ALLOWED_PILE: i32 = 10_000;
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        let len = piles.len();
        assert!(len % 3 == 0);
        let min = *piles.iter().min().unwrap();
        let max = *piles.iter().max().unwrap();
        assert!(max <= Self::MAX_ALLOWED_PILE && min > 0);
        let mut freqs = vec![0_i32; (max - min + 1) as usize];

        for p in piles {
            freqs[(p - min) as usize] += 1;
        }

        let target_cnt = (len / 3) * 2;
        let mut curr_idx = (max - min) as usize;
        let mut amount = 0_i32;
        for cnt in 0..target_cnt {
            while freqs[curr_idx] == 0 {
                curr_idx -= 1;
            }
            freqs[curr_idx] -= 1;
            if (cnt & 1) == 1 {
                amount += curr_idx as i32 + min;
            }
        }

        amount
    }
}
