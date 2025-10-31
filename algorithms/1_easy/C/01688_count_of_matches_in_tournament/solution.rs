impl Solution {
    pub fn number_of_matches(mut n: i32) -> i32 {
        let mut count = 0_i32;

        while n > 1 {
            count += (n >> 1);

            if (n & 1) == 1 {
                n = 1 + (n >> 1);
            } else {
                n = (n >> 1);
            }
        }

        count
    }
}
