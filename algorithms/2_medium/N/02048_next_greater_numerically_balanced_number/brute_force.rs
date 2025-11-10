impl Solution {
    fn is_beautifull(mut num: i32) -> bool {
        let mut freqs = [0_i32; 10];

        while num > 0 {
            freqs[(num % 10) as usize] += 1;
            num /= 10;
        }

        for i in 0..10_usize {
            if freqs[i] != 0 && freqs[i] != i as i32 {
                return false;
            }
        }

        true
    }

    pub fn next_beautiful_number(n: i32) -> i32 {
        let mut next = n + 1;

        loop {
            if Self::is_beautifull(next) {
                return next;
            }
            next += 1;
        }
    }
}
