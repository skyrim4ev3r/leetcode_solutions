impl Solution {
    pub fn fib(n: i32) -> i32 {
        let (mut prev, mut res) = (1, 0);

        for _ in 1..=n {
            (res, prev) = (res + prev, res);
        }

        res
    }
}
