use std::collections::HashMap;

impl Solution {
    fn dfs(n: i64, memo: &mut HashMap<i64, i32>) -> i32 {
        if n == 1 { return 0; }

        if let Some(val) = memo.get(&n) {
            return *val;
        }

        let res = if ((n & 1) == 0) {
            1 + Self::dfs(n / 2, memo)
        } else {
            1 + Self::dfs(n + 1, memo).min(Self::dfs(n - 1, memo))
        };

        memo.insert(n, res);
        return res;
    }

    pub fn integer_replacement(n: i32) -> i32 {
        debug_assert!(n > 0);
        let mut memo: HashMap::<i64, i32> = HashMap::default();

        Self::dfs(n as i64, &mut memo)
    }
}
