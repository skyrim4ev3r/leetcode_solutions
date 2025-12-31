use std::cmp::Ordering;

impl Solution {
    pub fn find_right_interval(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        let len = intervals.len();
        let starts = {
            let mut vec = intervals.iter()
                                   .enumerate()
                                   .map(|(i, x)| (x[0], i as i32))
                                   .collect::<Vec<_>>();
            vec.sort_unstable_by(|a, b| a.0.cmp(&b.0));
            vec
        };
        let mut res: Vec<i32> = Vec::with_capacity(len);

        for interval in intervals.iter() {
            let pos = starts.binary_search_by(|st|
                match st.0.cmp(&(interval[1])) {
                    Ordering::Less => Ordering::Less,
                    _ => Ordering::Greater
                }
            ).unwrap_or_else(|x| x);

            if pos == len {
                res.push(-1);
            } else {
                res.push(starts[pos].1);
            }
        }

        res
    }
}
