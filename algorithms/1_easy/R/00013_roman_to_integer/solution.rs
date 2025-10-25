impl Solution {
    pub fn roman_to_int(s: String) -> i32 {

        let mut sum = 0_i32;
        let mut curr_max = 0_i32;

        for byte in s.into_bytes().into_iter().rev() {

            let curr_num = match byte {
                b'I' => 1_i32,
                b'V' => 5_i32,
                b'X' => 10_i32,
                b'L' => 50_i32,
                b'C' => 100_i32,
                b'D' => 500_i32,
                b'M' => 1000_i32,
                _ => 0_i32,
            };

            if curr_num >= curr_max {
                sum += curr_num;
                curr_max = curr_num;
            } else {
                sum -= curr_num;
            }
        }

        sum
    }
}
