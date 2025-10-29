impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut x = 1_i32;

        while x <= n {
            x = x << 1;
        }

        x - 1
    }
}
