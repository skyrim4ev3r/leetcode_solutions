impl Solution {
    fn dfs(res: &mut Vec<i32>, mut curr: i32, n: i32) {
        if curr > n {
            return;
        }

        res.push(curr);
        curr *= 10;

        for i in 0..=9 {
            Self::dfs(res, curr + i, n);
        }
    }

    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::with_capacity(n as usize);

        for i in 1..=9 {
            Self::dfs(&mut res, i, n);
        }

        res
    }
}
