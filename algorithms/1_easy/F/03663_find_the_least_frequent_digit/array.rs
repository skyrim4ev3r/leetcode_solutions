impl Solution {
    pub fn get_least_frequent_digit(mut n: i32) -> i32 {
        let mut freqs = [0_u8; 10];

        while n > 0 {
            freqs[(n % 10) as usize] += 1;
            n /= 10;
        }

        freqs.into_iter()
             .enumerate()
             .filter(|(_, freq)| *freq > 0)
             .map(|(val_usize, freq)| (freq, val_usize as i32))
             .min()
             .unwrap()
             .1
    }
}
