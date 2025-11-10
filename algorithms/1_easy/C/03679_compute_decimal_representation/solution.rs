impl Solution {
    pub fn decimal_representation(n: i32) -> Vec<i32> {

        let mut p = 1;
        while n / p >= 10 {
            p *= 10;
        }

        let mut res: Vec<i32> = Vec::new();

        while p > 0 {
            let temp = ((n / p) % 10) * p;

            if temp != 0 {
                res.push(temp);
            }

            p /= 10;
        }

        res
    }
}
