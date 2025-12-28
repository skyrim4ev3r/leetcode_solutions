impl Solution {
    pub fn min_all_one_multiple(k: i32) -> i32 {
        if k % 2 == 0 || k % 5 == 0 {
            return -1;
        }

        let mut curr_rem = 0_i32;

        for dig_count in 1..=k {
            curr_rem = (curr_rem * 10 + 1) % k;

            if curr_rem == 0 {
                return dig_count;
            }
        }

        -1
    }
}
