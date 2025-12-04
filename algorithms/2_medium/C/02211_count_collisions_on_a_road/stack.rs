impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let mut stack: Vec<u8> = Vec::new();
        let mut count = 0_i32;

        for byte in directions.as_bytes().iter() {
            match *byte {
                b'L' => {
                    match stack.last() {
                        None => {},
                        Some(other_byte) => {
                            if *other_byte == b'S' {
                                count += 1;
                            } else {
                                count += 2;
                                stack.pop();

                                while let Some(other_byte) = stack.last() && *other_byte == b'R' {
                                    count += 1;
                                    stack.pop();
                                }

                                stack.clear();
                                stack.push(b'S');
                            }
                        }
                    };
                },
                b'R' => { 
                    stack.push(b'R');
                },
                b'S' => {
                    while let Some(other_byte) = stack.last() && *other_byte == b'R' {
                        count += 1;
                        stack.pop();
                    }

                    stack.clear();
                    stack.push(b'S');
                },
                _ => {}
            };
        }

        count
    }
}
