use std::collections::HashSet;

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {

        let n = a.len();
        let mut set: HashSet<i32> = HashSet::new();
        let mut res: Vec<i32> = Vec::with_capacity(n);
        let mut common = 0;

        for i in 0..n {
            if !set.insert(a[i]) {
                common += 1;
            }

            if !set.insert(b[i]) {
                common += 1;
            }

            res.push(common);
        }

        res
    }
}