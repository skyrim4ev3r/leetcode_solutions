impl Solution {
    pub fn number_of_points(mut nums: Vec<Vec<i32>>) -> i32 {
        nums.sort_unstable_by(|a, b| a[0].cmp(&b[0]));
        let mut count = 0_i32;
        let mut prev_right_point = i32::MIN;

        for point in nums.iter() {
            if prev_right_point >=  point[1] {
                continue;
            }

            if prev_right_point >=  point[0] {
                count += point[1] - prev_right_point;
                prev_right_point = point[1];
            } else {
                count += point[1] - point[0] + 1;
                prev_right_point = point[1];
            }
        }

        count
    }
}
