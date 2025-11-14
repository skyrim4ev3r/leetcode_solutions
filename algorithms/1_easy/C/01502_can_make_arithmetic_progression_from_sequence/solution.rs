impl Solution {
    pub fn can_make_arithmetic_progression(mut arr: Vec<i32>) -> bool {
        arr.sort_unstable();
        let diff = arr[1] - arr[0];

        for window in arr.windows(2).skip(1) {
            if window[1] - window[0] != diff {
                return false
            }
        }

        true
    }
}
