impl Solution {
    pub fn calculate_score(instructions: Vec<String>, values: Vec<i32>) -> i64 {
        let len = instructions.len();
        let mut curr_index = 0_usize;
        let mut curr_score = 0_i64;
        let mut seen = vec![false; len];

        while curr_index < len && !seen[curr_index] {
            seen[curr_index] = true;

            match instructions[curr_index].as_bytes() {
                b"jump" => {
                    curr_index = (curr_index as isize + values[curr_index] as isize) as usize;
                },
                b"add" => {
                    curr_score += values[curr_index] as i64;
                    curr_index += 1;
                },
                _ => panic!("invalid instructions"),
            }
        }

        curr_score
    }
}
