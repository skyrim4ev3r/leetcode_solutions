impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>) -> i32 {
        let len = colors.len();
        let mut count = 0_i32;

        for w in colors.windows(3) {
            if w[0] != w[1] && w[1] != w[2] {
                count += 1;
            }
        }

        if colors[0] != colors[1] && colors[0] != colors[len - 1] {
            count += 1;
        }

        if colors[len - 1] != colors[len - 2] && colors[len - 1] != colors[0] {
            count += 1;
        }

        count
    }
}
