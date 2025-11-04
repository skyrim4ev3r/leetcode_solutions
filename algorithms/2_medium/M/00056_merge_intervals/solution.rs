impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {

        let mut res: Vec<Vec<i32>> = Vec::new();

        intervals.sort_unstable_by(|a, b| a[0].cmp(&b[0]));

        for interval in intervals.into_iter() {
            if let Some(last) = res.last_mut() && last[1] >= interval[0] {
                last[1] = last[1].max(interval[1]);
            } else {
                res.push(interval);
            }
        }

        res
    }
}
