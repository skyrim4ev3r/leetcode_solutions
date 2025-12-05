impl Solution {
    pub fn get_sum(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let new_b = (b & a) << 1;
            a = a ^ b;
            b = new_b;
        }

        a
    }
}
