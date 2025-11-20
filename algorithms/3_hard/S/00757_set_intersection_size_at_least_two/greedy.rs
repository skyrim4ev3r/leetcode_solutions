impl Solution {
    pub fn intersection_size_two(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by(|a, b| a[1].cmp(&b[1]));
        let mut count = 0_i32;
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;

        for interval in intervals.iter() {
            if interval[0] == max1 {
                max2 = max1;
                count += 1;
                max1 = interval[1];
            } else if interval[0] > max1 {
                max1 = interval[1];
                max2 = max1 - 1;
                count += 2;
            } else if interval[0] > max2 {
                max2 = max1;
                max1 = interval[1];
                count += 1;
            }
        }

        count
    }
}
