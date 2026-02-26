use std::collections::HashSet;

impl Solution {
    pub fn recover_order(order: Vec<i32>, friends: Vec<i32>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::with_capacity(friends.len());
        let mut exact: HashSet<i32> = friends.into_iter().collect::<HashSet<_>>();

        for o in order.into_iter() {
            if exact.contains(&o) {
                res.push(o);
            }
        }

        res
    }
}
