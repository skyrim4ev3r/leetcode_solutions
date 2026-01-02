impl Solution {
    pub fn number_of_child(n: i32, mut k: i32) -> i32 {
        k %= 2 * (n - 1);

        if k < n {
            return k;
        } else {
            return n - 2 - (k - n);
        }
    }
}
