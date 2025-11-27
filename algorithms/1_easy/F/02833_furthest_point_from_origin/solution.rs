impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut balance = 0_i32;
        let mut offset = 0_i32;

        for byte in moves.as_bytes().iter() {
            match *byte {
                b'L' => balance -= 1,
                b'R' => balance += 1,
                _ => offset += 1,
            }
        }

        if balance < 0 {
            return (balance - offset).abs();
        }

        balance + offset
    }
}
