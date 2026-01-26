impl Solution {
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        arr.sort_unstable();

        let min = {
            let mut temp_min = i32::MAX;
            for window in arr.windows(2) {
                temp_min = temp_min.min(window[1] - window[0]);
            }

            temp_min
        };

        let mut res: Vec<Vec<i32>> = Vec::new();

        for window in arr.windows(2) {
            if min == window[1] - window[0] {
                res.push(window.to_vec());
            }
        }

        res
    }
}
