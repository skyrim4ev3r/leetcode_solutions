impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let mut prev_prev = 1_i32;
        let mut prev = 2_i32;
        let mut curr = 0_i32;

        for _ in 3..=n {
            curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }

        curr
    }
}
