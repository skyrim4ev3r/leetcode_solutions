use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn finding_users_active_minutes(logs: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut user_to_activity_count: HashMap<i32, i32> = HashMap::new();
        let logs_set: HashSet<_> = logs.into_iter().collect::<HashSet<_>>();
        let mut res: Vec<i32> = vec![0_i32; k as usize];

        for log in logs_set.iter() {
            *user_to_activity_count.entry(log[0]).or_insert(0) += 1;
        }

        for (_, count) in user_to_activity_count.iter() {
            res[(*count - 1) as usize] += 1;
        }

        res
    }
}
