impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {

        let mut count = 0_i32;
        let len = heights.len();

        let mut heights_sorted = heights.clone();
        heights_sorted.sort_unstable();

        for i in 0..len {
            if heights[i] != heights_sorted[i] {
                count += 1;
            }
        }

        count
    }
}
