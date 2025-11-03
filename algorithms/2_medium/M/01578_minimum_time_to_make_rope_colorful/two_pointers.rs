impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let mut left = 0_usize;
        let mut sum = 0_i32;
        let len = colors.len();
        let colors_bytes = colors.as_bytes();

        for right in 1..len {
            if colors_bytes[left] == colors_bytes[right] {
                if needed_time[left] < needed_time[right] {
                    sum += needed_time[left];
                    left = right;
                } else {
                    sum += needed_time[right];
                }
            } else {
                left = right;
            }
        }

        sum
    }
}
