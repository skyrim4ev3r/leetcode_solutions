impl Solution {
    pub fn h_index(mut citations: Vec<i32>) -> i32 {
        citations.sort_unstable_by(|a, b| b.cmp(&a));

        let mut res = 0_i32;

        for (i, citation) in citations.into_iter().enumerate() {
            let count = (i + 1) as i32;

            if citation >= count {
                res = count;
            } else {
                break;
            }
        }

        res
    }
}
