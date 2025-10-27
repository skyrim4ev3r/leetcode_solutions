impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {

        let mut prev_valid_count = 0_i32;
        let mut res = 0_i32;

        for row in bank.into_iter() {
            let mut curr_count = row.into_bytes().into_iter().filter(|&x| x == b'1').count() as i32;

            if curr_count > 0 {
                res += prev_valid_count * curr_count;
                prev_valid_count = curr_count;
            }
        }

        res
    }
}
