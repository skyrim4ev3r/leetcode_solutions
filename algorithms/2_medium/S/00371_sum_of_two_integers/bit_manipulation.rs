impl Solution {
    #[inline(always)]
    fn get_sum_helper(mut a: u32, mut b: u32) -> u32 {
        while b != 0 {
            let new_b = (b & a) << 1;
            a = a ^ b;
            b = new_b;
        }

        a
    }
    pub fn get_sum(mut a: i32, mut b: i32) -> i32 {
        Self::get_sum_helper(a as u32, b as u32) as i32
    }
}
