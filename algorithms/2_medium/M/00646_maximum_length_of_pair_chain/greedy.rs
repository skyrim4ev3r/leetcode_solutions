impl Solution {
    pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
        pairs.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

        let mut curr_end = pairs[0][1];
        let mut count = 1_i32;

        for p in pairs.into_iter().skip(1) {
            if p[0] > curr_end {
                curr_end = p[1];
                count += 1;
            }
        }

        count
    }
}
