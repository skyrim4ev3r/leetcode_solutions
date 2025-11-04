impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by(|a, b| {
            if (a[0] == b[0]) {
                a[1].cmp(&b[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let mut left = 0_usize;
        let len = intervals.len();
        let mut count = 0_i32;

        for right in 1..len {
            if intervals[left][1] <= intervals[right][0] {
                left = right;
            } else {
                if intervals[right][1] < intervals[left][1] {
                    left = right;
                }

                count += 1;
            }
        }

        count
    }
}
