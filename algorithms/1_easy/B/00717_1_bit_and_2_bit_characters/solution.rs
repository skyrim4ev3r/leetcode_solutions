impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let len = bits.len();
        let mut index = 0_usize;
        let mut last_is_zero = false;

        while index < len {
            if bits[index] == 0 {
                last_is_zero = true;
                index += 1;
            } else {
                last_is_zero = false;
                index += 2;
            }
        }

        last_is_zero
    }
}
