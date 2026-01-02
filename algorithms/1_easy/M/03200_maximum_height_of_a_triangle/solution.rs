impl Solution {
    pub fn max_height_of_triangle(red: i32, blue: i32) -> i32 {
        let mut curr_height = 0_i32;
        let mut odd_count = 0_i32;
        let mut even_count = 0_i32;
        let mut curr_level = 1_i32;

        loop {
            if (curr_level & 1) == 1 {
                odd_count += curr_level;
            } else {
                even_count += curr_level;
            }

            if !((odd_count <= red && even_count <= blue) || (odd_count <= blue && even_count <= red)) {
                return curr_level - 1;
            }

            curr_level += 1;
        }
    }
}
