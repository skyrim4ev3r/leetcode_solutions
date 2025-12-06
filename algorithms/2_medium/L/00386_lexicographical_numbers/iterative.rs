impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::with_capacity(n as usize);
        let mut curr = 1_i32;

        for _ in 1..=n {
            res.push(curr);

            if curr * 10 <= n {
                curr *= 10;
            } else {
                while curr % 10 == 9 || curr + 1 > n {
                    curr /= 10;
                }

                curr += 1;
            }
        }

        res
    }
}
