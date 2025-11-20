impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut consecutive_odd_count = 0_u8;

        for num in arr.iter() {
            if num % 2 == 1 {
                consecutive_odd_count += 1;
            } else {
                consecutive_odd_count = 0;
            }

            if consecutive_odd_count == 3 {
                    return true;
            }
        }

        false
    }
}
