use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut set: HashSet<i32> = HashSet::new();

        for num in arr.into_iter() {
            if set.contains(&(num * 2)) || ((num & 1) != 1 && set.contains(&(num / 2))) {
                return true;
            }

            set.insert(num);
        }

        false
    }
}
