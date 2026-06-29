impl Solution {
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        let len = piles.len();
        assert!(len % 3 == 0);
        piles.sort_unstable();

        let mut j = len as isize - 2;
        let mut i = 0_isize;
        let mut amount = 0_i32;

        while i < j {
            amount += piles[j as usize];
            j -= 2;
            i += 1;
        }

        amount
    }
}
