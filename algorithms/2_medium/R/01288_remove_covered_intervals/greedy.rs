impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by(|a, b| a[0].cmp(&b[0]).then_with(|| b[1].cmp(&a[1])));

        let len = intervals.len();
        let mut invalids_count = 0_usize;
        let mut prev_end = intervals[0][1];

        for i in 1..len {
            if intervals[i][1] <=  prev_end {
                invalids_count += 1;
            } else {
                prev_end = intervals[i][1];
            }
        }

        (len - invalids_count) as i32
    }
}
