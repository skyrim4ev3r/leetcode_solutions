impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let mut count_5s = 0_i32;
        let mut count_10s = 0_i32;

        for &bill in bills.iter() {
            if bill == 5 {
                count_5s += 1;
            } else if bill == 10 {
                if count_5s > 0 {
                    count_5s -= 1;
                    count_10s += 1;
                } else {
                    return false;
                }
            } else if bill == 20 {
                if count_10s > 0 && count_5s > 0 {
                    count_10s -= 1;
                    count_5s -= 1;
                } else if count_5s >= 3 {
                    count_5s -= 3;
                } else {
                    return false;
                }
            }
        }

        true
    }
}
