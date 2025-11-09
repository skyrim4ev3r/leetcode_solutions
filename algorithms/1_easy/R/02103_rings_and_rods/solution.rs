impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let len = rings.len();
        let colors: [i32; 3] = [1, 2, 4];
        let rings_bytes = rings.as_bytes();

        let mut rods = [0_i32; 10];

        for i in (0..len).step_by(2) {
            let rod_index = (rings_bytes[i + 1] - b'0') as usize;
            let color_index = if rings_bytes[i] == b'R' {
                                0_usize
                              } else if rings_bytes[i] == b'G' {
                                1_usize
                              } else {
                                2_usize
                              };

            rods[rod_index] |= colors[color_index];
        }

        rods.into_iter().filter(|x| *x == 7).count() as i32
    }
}
