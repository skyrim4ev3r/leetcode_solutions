impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let mut count = 0_i32;
        let mut curr_r = 0_i32;
        let mut curr_s = 0_i32;

        for byte in directions.as_bytes().iter() {
            match *byte {
                b'L' => {
                    if curr_r > 0 {
                        count += curr_r + 1;
                        curr_r = 0;
                        curr_s = 1;
                    } else if curr_s != 0 {
                            count += 1;
                    }
                },
                b'R' => {
                    curr_r += 1;
                },
                b'S'=> {
                    count += curr_r;
                    curr_r = 0;
                    curr_s = 1;
                },
                _ => {},
            }
        }

        count
    }
}
