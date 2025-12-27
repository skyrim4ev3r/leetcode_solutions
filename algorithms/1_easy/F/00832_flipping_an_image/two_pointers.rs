impl Solution {
    pub fn flip_and_invert_image(mut image: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        for row in image.iter_mut() {
            let mut right = row.len() - 1;
            let mut left = 0_usize;

            while left < right {
                let temp = row[left];
                row[left] = row[right];
                row[right] = temp;

                row[right] = if row[right] == 1 {0} else {1};
                row[left] = if row[left] == 1 {0} else {1};

                left += 1;
                right -= 1;
            }

            if left == right {
                row[left] = if row[left] == 1 {0} else {1};
            }
        }

        image
    }
}
