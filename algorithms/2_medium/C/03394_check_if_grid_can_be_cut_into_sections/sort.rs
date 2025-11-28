impl Solution {
    pub fn check_valid_cuts(n: i32, mut rectangles: Vec<Vec<i32>>) -> bool {
        rectangles.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

        let mut count = 1_i32;
        let mut prev_end = rectangles[0][3];

        for rectangle in rectangles.iter().skip(1) {
            if rectangle[1] < prev_end {
                prev_end = prev_end.max(rectangle[3]);
            } else {
                count += 1;

                if count == 3 {
                    return true;
                }

                prev_end = rectangle[3];
            }
        }

        rectangles.sort_unstable_by(|a, b| a[0].cmp(&b[0]));
        count = 1;
        prev_end = rectangles[0][2];

        for rectangle in rectangles.iter().skip(1) {
            if rectangle[0] < prev_end {
                prev_end = prev_end.max(rectangle[2]);
            } else {
                count += 1;

                if count == 3 {
                    return true;
                }

                prev_end = rectangle[2];
            }
        }

        false
    }
}
