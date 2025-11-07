impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::with_capacity(n as usize);

        for i in 1..=(n / 2) {
            res.push(i);
            res.push(-1 * i);
        }

        if n % 2 == 1 {
            res.push(0);
        }

        res
    }
}
