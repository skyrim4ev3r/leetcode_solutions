impl Solution {
    pub fn has_alternating_bits(mut n: i32) -> bool {
        let mut prev_remainder = -1;

        while n > 0 {
            let curr_remainder = (n & 1);
            if curr_remainder == prev_remainder {
                return false;
            }

            prev_remainder = curr_remainder;
            n = (n >> 1);;
        }

        true
    }
}
