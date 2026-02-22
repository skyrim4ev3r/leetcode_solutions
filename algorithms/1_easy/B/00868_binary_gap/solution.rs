impl Solution {
    const BITS_COUNT: usize = 32;

    pub fn binary_gap(n: i32) -> i32 {
        let mut prev_valid_bit: Option<usize> = None;
        let mut max_dist = 0_usize;

        for i in 0..Self::BITS_COUNT {
            let mask: i32 = 1 << i;

            if (mask & n) != 0 {
                if let Some(pos) = prev_valid_bit {
                    max_dist = max_dist.max(i - pos);
                }

                prev_valid_bit = Some(i);
            }
        }

        max_dist as i32
    }
}
