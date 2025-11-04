impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

        let len = intervals.len();
        let mut prev_end = intervals[0][1];
        let mut count = 0_i32;

        for i in 1..len {
            if intervals[i][0] >= prev_end {
                prev_end = intervals[i][1];
            } else {
                count += 1;
            }
        }

        count
    }
}
