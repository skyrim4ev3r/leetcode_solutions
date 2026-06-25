impl Solution {
    pub fn max_distance(moves: String) -> i32 {
        let mut lr = 0_i32;
        let mut ud = 0_i32;
        let mut extra = 0_i32;

        for &byte in moves.as_bytes() {
            match byte {
                b'U' => ud += 1,
                b'D' => ud -= 1,
                b'R' => lr += 1,
                b'L' => lr -= 1,
                b'_' => extra += 1,
                _ => unreachable!("invalid input"),
            }
        }

        ud.abs() + lr.abs() + extra
    }
}
