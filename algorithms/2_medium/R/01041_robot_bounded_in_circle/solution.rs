impl Solution {
    const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    pub fn is_robot_bounded(instructions: String) -> bool {
        let mut x = 0_i32;
        let mut y = 0_i32;
        let mut curr_dir_index = 0_usize;

        for byte in instructions.as_bytes().iter() {
            if *byte == b'G' {
                let (dx, dy) = Self::DIRECTIONS[curr_dir_index];
                y += dy;
                x += dx;
            } else if *byte == b'L' {
                curr_dir_index = if curr_dir_index == 0 {3} else {curr_dir_index - 1};
            } else {
                curr_dir_index = if curr_dir_index == 3 {0} else {curr_dir_index + 1};
            }
        }

        (x == 0 && y == 0) || curr_dir_index != 0
    }
}
