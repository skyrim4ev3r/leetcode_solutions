impl Solution {
    pub fn minimum_flips(n: i32) -> i32 {
        let mut rev = 0_i32;
        let mut temp = n;

        while temp > 0 {
            rev = rev << 1;

            if (temp & 1) == 1 {
                rev |= 1;
            }

            temp = temp >> 1;
        }

        (rev ^ n).count_ones() as i32
    }
}
