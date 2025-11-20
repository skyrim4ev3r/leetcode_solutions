impl Solution {
    pub fn final_position_of_snake(n: i32, commands: Vec<String>) -> i32 {
        let mut i = 0_i32;
        let mut j = 0_i32;

        for command in commands.iter() {
            match command.as_str() {
                "RIGHT" => j += 1,
                "LEFT" => j -= 1,
                "UP" => i -= 1,
                "DOWN" => i += 1,
                _ => {},
            }
        }

        i * n + j
    }
}
