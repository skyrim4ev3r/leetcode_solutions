impl Solution {
    pub fn judge_circle(moves: String) -> bool {

        if (moves.len() & 1) == 1 {
            return false;
        }

        let mut lr = 0_i32;
        let mut ud = 0_i32;

        for byte in moves.into_bytes().into_iter() {
            match byte {
                b'U' => ud += 1,
                b'D' => ud -= 1,
                b'R' => lr += 1,
                b'L' => lr -= 1,
                _ => {}
            }
        }

        lr == 0 && ud == 0
    }
}
